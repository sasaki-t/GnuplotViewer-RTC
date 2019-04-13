// -*- C++ -*-
/*!
 * @file  gnuplot_view.h
 * @brief gnuplot class header file
 * @date $Date$
 *
 * @author ç≤ÅXñÿãB (Takeshi SASAKI) 
 * sasaki-t(_at_)ieee.org
 *
 *
 */

#ifndef GNUPLOT_VIEW_H
#define GNUPLOT_VIEW_H

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <new>
#include <stdexcept>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

/*!
 * @class Gnuplot
 * @brief Gnuplot class
 */
class Gnuplot{
	FILE* GP;

	std::string tmpfile_path; //where temporary files will be stored
	
	//gnuplot data file
	std::ofstream data_file;
	std::vector< std::string > data_filename;

public:
	Gnuplot(const char *f_path = ".");
	~Gnuplot();

	int initialize(const char *gp_path = NULL, const char *option = NULL);
	int finalize();
	int addData(const char *f_name_base);
	int deleteData(const char* filename);
	int deleteData(std::vector<std::string>::size_type file_index);

	/*!
	 * @brief Get data file name from its index
	 * @param i Index of data file
	 * @return Datafile name
	 */
	const char* getDataFilename(std::vector<std::string>::size_type i){
		try{
			return data_filename.at(i).c_str();
		}
		catch(std::out_of_range){
			std::cerr << "Error in Gnuplot::getDataFilename(): Invaled argument" << std::endl;
			return NULL;
		}
	}

	/*!
	 * @brief Send command to gnuplot
	 * @param cmd Command
	 * @return 0 if no error
	 */
	int sendCommand(const char* cmd){
		if(GP == NULL){
			std::cerr << "Error in Gnuplot::sendCommand(): Gnuplot not opened" << std::endl;
			return 1;
		}

		std::fprintf(GP, "%s\n", cmd);
		std::fflush(GP);

		return 0;
	}

	/*!
	 * @brief Output 1D vector data to file using specified format
	 * @param filename Filename
	 * @param data_vect 1D data vector
	 * @param separate_pos NL is inserted in each separate_pos data
	 * @return 0 if no error
	 */
	template <class T>
	int setData(const char* filename, std::vector<T>& data_vect, int separate_pos = 1){
		std::vector<std::string>::size_type i;
		for(i=0;i<data_filename.size();i++){
			if(data_filename[i] == filename){
				setData(i, data_vect, separate_pos);
				return 0;
			}
		}

		std::cerr << "Error in Gnuplot::getData(): Invaled argument" << std::endl;
		return 1;
	}

	/*!
	 * @brief Output 1D vector data to file using specified format
	 * @param file_index Index of output file
	 * @param data_vect 1D data vector
	 * @param separate_pos NL is inserted in each separate_pos data
	 * @return 0 if no error
	 */
	template <class T>
	int setData(std::vector<std::string>::size_type file_index, std::vector<T>& data_vect, int separate_pos = 1){
		typename std::vector<T>::size_type i;
		typename std::vector<T>::size_type d_size = data_vect.size();
		int count=0;

		if(separate_pos <= 0){separate_pos = 1;}

		//close file if opened
		if(data_file.is_open()){
			data_file.close();
		}

		//open file
		try{
			data_file.open(data_filename.at(file_index).c_str(), std::ios::out);
		}catch(std::out_of_range){
			std::cerr << "Error in Gnuplot::getData(): Invaled argument" << std::endl;
			return 1;
		}
		if(!data_file) {
			std::cerr << "Error in Gnuplot::getData(): Cannot open file" << std::endl;
			return 2;
		}


		//write data
		for(i=0;i<d_size;i++){
			data_file << data_vect[i] << ' ';
			count++;
			if(count == separate_pos){
				data_file << std::endl;
				count = 0;
			}
		}

		//close file
		data_file.close();

		return 0;
	}
};

int convert_alias_to_filename(Gnuplot &gp, std::string &s, const char* name_base, const char* preindex, const char* postindex, std::vector<std::string>::size_type index_start, std::vector<std::string>::size_type index_num);
void convert_backslash_to_slash(std::string &s);
#endif //GNUPLOT_VIEW_H

