// -*- C++ -*-
/*!
 * @file  gnuplot_view.cpp
 * @brief gnuplot class implementation
 * @date $Date$
 *
 * @author ç≤ÅXñÿãB (Takeshi SASAKI) 
 * sasaki-t(_at_)ieee.org
 *
 *
 */

#include "gnuplot_view.h"

using namespace std;

/*!
 * @brief Constructor
 */
Gnuplot::Gnuplot(const char *f_path){
	tmpfile_path = f_path;

	if(tmpfile_path.empty()){ //if empty stirng - set current path
#if defined(_WIN32) || defined(_WIN64)
		tmpfile_path = ".\\";
#else
		tmpfile_path = "./";
#endif
	}else if((tmpfile_path[tmpfile_path.size()-1] != '/')&&(tmpfile_path[tmpfile_path.size()-1] != '\\')){ //if last character is not "/"
#if defined(_WIN32) || defined(_WIN64)
		tmpfile_path.push_back('\\');
#else
		tmpfile_path.push_back('/');
#endif
	}

	GP = NULL;
}

/*!
 * @brief Destructor
 */
Gnuplot::~Gnuplot(){
	finalize();
}

/*!
 * @brief Open gnuplot
 * @param gp_path Path of the gnuplot
 * @param option Open option
 * @return 0 if no error, 1 if open error
 */
int Gnuplot::initialize(const char *gp_path, const char *option){
	string cmd = gp_path;

	if(GP != NULL){ //already opened
		cerr << "Gnuplot already opened. Finalize and initialize again" << endl;
		finalize();
	}

	if(!cmd.empty()){
		if((cmd[cmd.size()-1] != '/')&&(cmd[cmd.size()-1] != '\\')){ //if last character is not "/"
#if defined(_WIN32) || defined(_WIN64)
			cmd.push_back('\\');
#else
			cmd.push_back('/');
#endif
		}
	}
#if defined(_WIN32) || defined(_WIN64)
	cmd += "gnuplot.exe"; //"pgnuplot.exe"
#else
	cmd += "gnuplot";
#endif

	if(option != NULL){
		cmd += ' ';
		cmd += option;
	}
#if defined(_WIN32) || defined(_WIN64)
	GP = _popen(cmd.c_str(),"w");
#else
	GP = popen(cmd.c_str(),"w");
#endif
	if(GP == NULL){
		cerr << "Error in Gnuplot::initialize(): Cannot open gnuplot" << endl;
		return 1;
	}

	if(cmd.find("-raise")==string::npos){
#if defined(_WIN32) || defined(_WIN64)
		//set default terminal to wxt and noraise
		sendCommand("set terminal wxt noraise");
#else
		//set default terminal to x11 and noraise
		sendCommand("set terminal x11 noraise");
#endif
	}else{
#if defined(_WIN32) || defined(_WIN64)
		sendCommand("set terminal wxt");
#else
		sendCommand("set terminal x11");
#endif
	}

	return 0;
}

/*!
 * @brief Close gnuplot and remove all temporary files
 * @return 0 if no error, 1 if some files cannot be removed
 */
int Gnuplot::finalize(){
	//unsigned int i;
	//int res;

	//close gnuplot if opened
	if(GP != NULL){
#if defined(_WIN32) || defined(_WIN64)
		_pclose(GP);
#else
		pclose(GP);
#endif
		GP = NULL;
	}

	//close file if opened
	if(data_file.is_open()){
		data_file.close();
	}

	//remove tmpfile
	while(!data_filename.empty()){
		deleteData(data_filename.size()-1);
	}
/*
	for(i=0; i<data_filename.size(); i++){
		res = remove(data_filename[i].c_str());
		if(res == 0){
			cerr << "delete data: " << data_filename[i] << endl;
		}else{
			perror("cannot delete data: ");
		}
	}
	data_filename.clear();
*/

	return 0;
}

/*!
 * @brief Make data file
 * @param f_name_base Template name for temporary file
 * @return 0 if no error, 1 if allocation error, 2 if file open error, 3 if file close error
 */
int Gnuplot::addData(const char *f_name_base){
	int res;
	char* st = NULL;
	unsigned int buf_size;
	string f_name;

	//allocate memory for file name
#if defined(_WIN32) || defined(_WIN64)
	buf_size = MAX_PATH;
#else
	int fd; //file descriptor

	f_name = (tmpfile_path + f_name_base) + "XXXXXX"; //for calculating file name length
	buf_size = (unsigned int)f_name.size() + 1;
#endif

	try{
		st = new char[buf_size];
	}
	catch(bad_alloc){
		cerr << "Error in Gnuplot::addData(): BAD ALLOC Exception" << endl;
		return 1;
	}

	//create unique file name
#if defined(_WIN32) || defined(_WIN64)
	res = GetTempFileName(tmpfile_path.c_str(),f_name_base,0,st);
	if(res==0){
		cerr << "Error in Gnuplot::addData(): Cannot open file" << endl;
		delete [] st;
		return 2;	
	}
#else
	sprintf(st, "%s", f_name.c_str()); //copy the path to st
	fd = mkstemp(st); //generate a unique temporary file name and get its file descriptor
	if(fd == -1){
		cerr << "Error in Gnuplot::addData(): Cannot open file" << endl;
		delete [] st;
		return 2;
	}

	res = close(fd); //close file descriptor
	if(res != 0){
		cerr << "Error in Gnuplot::addData(): Close failed" << endl;
		delete [] st;
		return 3;
	}
#endif

	//store file name to f_name
	f_name = st;
	delete [] st;
	st = NULL;


	//make data file
	//close file if opened
	if(data_file.is_open()){
		data_file.close();
	}
	//open file
	data_file.open(f_name.c_str(), ios::out);
	if(!data_file) {
		cerr << "Error in Gnuplot::addData(): Cannot open file" << endl;
		return 2;
	}

	data_file.close();

	//store filename to data file name vector
/*
#ifdef DEBUG
	cerr << "add data: " << f_name << endl;
#endif
*/
	data_filename.push_back(f_name);

	return 0;
}

/*!
 * @brief Remove specified temporary file
 * @param filename Name of the file deleted
 * @return 0 if no error, 1 if cannot find specified file name
 */
int Gnuplot::deleteData(const char* filename){
	unsigned int i;
	for(i=0;i<data_filename.size();i++){
		if(data_filename[i] == filename){
			deleteData(i);
			return 0;
		}
	}

	cerr << "Error in Gnuplot::deleteData(): Invaled argument" << endl;
	return 1;
}

/*!
 * @brief Remove specified temporary file
 * @param file_index Index of the file deleted
 * @return 0 if no error, 1 if cannot find specified file index
 */
int Gnuplot::deleteData(std::vector<std::string>::size_type file_index){
	int res;

	//close file if opened
	if(data_file.is_open()){
		data_file.close();
	}

	try{
		//remove tmpfile
		res = remove(data_filename.at(file_index).c_str());
	}
	catch(out_of_range){
		cerr << "Error in Gnuplot::deleteData(): Invaled argument" << endl;
		return 1;
	}

	if(res == 0){
/*
#ifdef DEBUG
		cerr << "delete data: " << data_filename << endl;
#endif
*/
	}else{
		perror("cannot delete data: ");
	}

	//delete data from vector
	vector< string >::iterator it_st = data_filename.begin();
	advance(it_st,file_index);

	it_st = data_filename.erase(it_st);

	return 0;
}


/*!
 * @brief Convert name_base+preindex+index+postindex to temporary file name
 * @param gp Reference to gnuplot
 * @param s String which may contain alias
 * @param name_base Alias information
 * @param preindex Alias information
 * @param postindex Alias information
 * @param index_start Search region for data files
 * @param index_num Search region for data files
 * @return 0 if no error, 1 if invalid index error
 */
int convert_alias_to_filename(Gnuplot &gp, string &s, const char* name_base, const char* preindex, const char* postindex, std::vector<std::string>::size_type index_start, std::vector<std::string>::size_type index_num){
	std::vector<std::string>::size_type vect_index;
	string::size_type loc1=0, loc2=0;
	string name = name_base;
	string str_repl;
	name += preindex;

	//convert to tmporary file name
	for(;;){
		loc1 = s.find(name,loc1); 
		if(loc1 != string::npos){ //find name_base+preindex
			loc2 = s.find(postindex, loc1+name.size()); //find post index
			if(loc2 != string::npos){
				if(( !((s.substr(loc1+name.size(), loc2-loc1-name.size())).empty()) ) && ((s.substr(loc1+name.size(), loc2-loc1-name.size())).find_first_not_of("0123456789") == string::npos)){ //characters between pre- and postindex are only numbers
					vect_index = (std::vector<std::string>::size_type) atoi(s.substr(loc1+name.size(), loc2-loc1-name.size()).c_str());
					if(vect_index < index_num){
						if(gp.getDataFilename(index_start + vect_index) != NULL){
							s = s.replace(loc1, loc2-loc1+1, gp.getDataFilename(index_start + vect_index));
							loc1 = 0;
							continue;
						}else{
							cerr << "Error in convert_alias_to_filename(): Invaled index" << endl;
							return 1;
						}
					}
				}
				loc1 += 1;
				continue;
			}
		}
		break;
	}
	//convert backslash to slash since gnuplot only accept slash for specifying the file path
	convert_backslash_to_slash(s);

	return 0;
}

/*!
 * @brief Convert backslash (\) in string s to slash (/)
 * @param s String which may contain backslash
 */
void convert_backslash_to_slash(std::string &s){
	std::string::iterator it=s.begin();
	while(it != s.end()){
		if(*it == '\\'){
			*it = '/';
		}
		it++;
	}
	return;
}
