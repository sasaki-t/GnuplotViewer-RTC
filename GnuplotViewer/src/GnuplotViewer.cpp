// -*- C++ -*-
/*!
 * @file  GnuplotViewer.cpp
 * @brief Versatile viewer component using gnuplot
 * @date $Date$
 *
 * @author 佐々木毅 (Takeshi SASAKI)
 * sasaki-t(_at_)ieee.org
 *
 * $Id$
 */

#include <iostream>
#include <cstdlib>

#include "GnuplotViewer.h"

// Module specification
// <rtc-template block="module_spec">
static const char* gnuplotviewer_spec[] =
  {
    "implementation_id", "GnuplotViewer",
    "type_name",         "GnuplotViewer",
    "description",       "Versatile viewer component using gnuplot",
    "version",           "1.1.0",
    "vendor",            "TakeshiSasaki",
    "category",          "generic",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "0",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.gpOpenOption", "*",
    "conf.default.gpSeparatePos", "1",
    "conf.default.gpPeriodicExecCommand", "*",
    "conf.default.pShortInPortNum", "0",
    "conf.default.pLongInPortNum", "0",
    "conf.default.pFloatInPortNum", "0",
    "conf.default.pDoubleInPortNum", "0",
    "conf.default.gpPath", "*",

    // Widget
    "conf.__widget__.gpOpenOption", "text",
    "conf.__widget__.gpSeparatePos", "text",
    "conf.__widget__.gpPeriodicExecCommand", "text",
    "conf.__widget__.pShortInPortNum", "text",
    "conf.__widget__.pLongInPortNum", "text",
    "conf.__widget__.pFloatInPortNum", "text",
    "conf.__widget__.pDoubleInPortNum", "text",
    "conf.__widget__.gpPath", "text",
    // Constraints
    "conf.__constraints__.pShortInPortNum", "x>=0",
    "conf.__constraints__.pLongInPortNum", "x>=0",
    "conf.__constraints__.pFloatInPortNum", "x>=0",
    "conf.__constraints__.pDoubleInPortNum", "x>=0",

    "conf.__type__.gpOpenOption", "string",
    "conf.__type__.gpSeparatePos", "string",
    "conf.__type__.gpPeriodicExecCommand", "string",
    "conf.__type__.pShortInPortNum", "int",
    "conf.__type__.pLongInPortNum", "int",
    "conf.__type__.pFloatInPortNum", "int",
    "conf.__type__.pDoubleInPortNum", "int",
    "conf.__type__.gpPath", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
GnuplotViewer::GnuplotViewer(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_CommandIn("Command", m_Command),
    m_ShortSeqDataIn("ShortSeqData"),
    m_LongSeqDataIn("LongSeqData"),
    m_FloatSeqDataIn("FloatSeqData"),
    m_DoubleSeqDataIn("DoubleSeqData")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
GnuplotViewer::~GnuplotViewer()
{
}



RTC::ReturnCode_t GnuplotViewer::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("Command", m_CommandIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("gpOpenOption", m_gpOpenOption, "*");
  bindParameter("gpSeparatePos", m_gpSeparatePos, "1");
  bindParameter("gpPeriodicExecCommand", m_gpPeriodicExecCommand, "*");
  bindParameter("pShortInPortNum", m_pShortInPortNum, "0");
  bindParameter("pLongInPortNum", m_pLongInPortNum, "0");
  bindParameter("pFloatInPortNum", m_pFloatInPortNum, "0");
  bindParameter("pDoubleInPortNum", m_pDoubleInPortNum, "0");
  bindParameter("gpPath", m_gpPath, "*");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t GnuplotViewer::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GnuplotViewer::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GnuplotViewer::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*!
 * Configurationのp{Short,Long,Float,Double}InPortNumの値に応じて動
 * 的入力ポートの生成を行う。
 * また、gnuplotを起動する。
 * このとき、ConfigurationのgpOpenOptionにgnuplotの起動オプションが
 * 与えられていれば、そのオプションにしたがってgnuplotをオープンす
 * る。
 */

RTC::ReturnCode_t GnuplotViewer::onActivated(RTC::UniqueId ec_id)
{
  std::string gp_str, op_str;

  const char* dataFileName = "dat";

  int i;
  unsigned int j;
  int pnum;
  int res;

  m_CommandIn.read();

  // ******* set dynamic ports *********************************** //
  pnum = m_pShortInPortNum;
  for(i=0;i<pnum;i++){
    res = m_ShortSeqDataIn.addPort();
    if(res==0){
      addInPort(m_ShortSeqDataIn.getName(m_ShortSeqDataIn.getSize()-1), m_ShortSeqDataIn.m_port[m_ShortSeqDataIn.getSize()-1]);
      m_ShortSeqDataIn.m_port[m_ShortSeqDataIn.getSize()-1].read();
    }
  }
  pnum = m_pLongInPortNum;
  for(i=0;i<pnum;i++){
    res = m_LongSeqDataIn.addPort();
    if(res==0){
      addInPort(m_LongSeqDataIn.getName(m_LongSeqDataIn.getSize()-1), m_LongSeqDataIn.m_port[m_LongSeqDataIn.getSize()-1]);
      m_LongSeqDataIn.m_port[m_LongSeqDataIn.getSize()-1].read();
    }
  }
  pnum = m_pFloatInPortNum;
  for(i=0;i<pnum;i++){
    res = m_FloatSeqDataIn.addPort();
    if(res==0){
      addInPort(m_FloatSeqDataIn.getName(m_FloatSeqDataIn.getSize()-1), m_FloatSeqDataIn.m_port[m_FloatSeqDataIn.getSize()-1]);
      m_FloatSeqDataIn.m_port[m_FloatSeqDataIn.getSize()-1].read();
    }
  }
  pnum = m_pDoubleInPortNum;
  for(i=0;i<pnum;i++){
    res = m_DoubleSeqDataIn.addPort();
    if(res==0){
      addInPort(m_DoubleSeqDataIn.getName(m_DoubleSeqDataIn.getSize()-1), m_DoubleSeqDataIn.m_port[m_DoubleSeqDataIn.getSize()-1]);
      m_DoubleSeqDataIn.m_port[m_DoubleSeqDataIn.getSize()-1].read();
    }
  }

  // ******* open gnuplot *********************************** //
  // get path of the gnuplot
  gp_str = m_gpPath;
  if(gp_str == "*"){ //current path ("*": default message)
    gp_str = "";
  }

  // get open option if m_gpOpenOption is set
  op_str = m_gpOpenOption;
  if((op_str.empty()) || (op_str == "*")){ //no option ("*": default message)
    res = gp.initialize(gp_str.c_str());
  }else{ //option is set
    res = gp.initialize(gp_str.c_str(), op_str.c_str());
  }

  //Open error
  if(res!=0){
    return RTC::RTC_ERROR;
  }

  // ******* set gnuplot data for each port ********************** //
  //short port
  for(j=0;j<m_ShortSeqDataIn.getSize();j++){
    res = gp.addData(dataFileName);
    //error in set temporary file
    if(res!=0){
      return RTC::RTC_ERROR;
    }
  }
  //long port
  for(j=0;j<m_LongSeqDataIn.getSize();j++){
    res = gp.addData(dataFileName);
    //error in set temporary file
    if(res!=0){
      return RTC::RTC_ERROR;
    }
  }
  //float port
  for(j=0;j<m_FloatSeqDataIn.getSize();j++){
    res = gp.addData(dataFileName);
    //error in set temporary file
    if(res!=0){
      return RTC::RTC_ERROR;
    }
  }
  //double port
  for(j=0;j<m_DoubleSeqDataIn.getSize();j++){
    res = gp.addData(dataFileName);
    //error in set temporary file
    if(res!=0){
      return RTC::RTC_ERROR;
    }
  }

  return RTC::RTC_OK;
}

/*!
 * 動的入力ポートの削除とgnuplotのクローズを行う。
 */

RTC::ReturnCode_t GnuplotViewer::onDeactivated(RTC::UniqueId ec_id)
{
  separate_list.clear();
  periodic_cmd.clear();

  gp.finalize();

  //delete port... put removePort first!!
  while(m_ShortSeqDataIn.getSize() > 0){
    removeInPort(m_ShortSeqDataIn.m_port[m_ShortSeqDataIn.getSize()-1]);
    m_ShortSeqDataIn.deletePort(m_ShortSeqDataIn.getSize()-1);
  }
  while(m_LongSeqDataIn.getSize() > 0){
    removeInPort(m_LongSeqDataIn.m_port[m_LongSeqDataIn.getSize()-1]);
    m_LongSeqDataIn.deletePort(m_LongSeqDataIn.getSize()-1);
  }
  while(m_FloatSeqDataIn.getSize() > 0){
    removeInPort(m_FloatSeqDataIn.m_port[m_FloatSeqDataIn.getSize()-1]);
    m_FloatSeqDataIn.deletePort(m_FloatSeqDataIn.getSize()-1);
  }
  while(m_DoubleSeqDataIn.getSize() > 0){
    removeInPort(m_DoubleSeqDataIn.m_port[m_DoubleSeqDataIn.getSize()-1]);
    m_DoubleSeqDataIn.deletePort(m_DoubleSeqDataIn.getSize()-1);
  }

  return RTC::RTC_OK;
}

/*!
 * InPortのCommandに送られてきたgnuplotのコマンドを実行する。
 * InPortの{Short,Long,Float,Double}SeqDataに送られてきたデータをC
 * onfigurationのgpSeparatePosの形式にしたがって保存する。
 * 新しいデータが入力される度にConfigurationのgpPeriodicExecComman
 * dに記入されたコマンドを実行する。
 */

RTC::ReturnCode_t GnuplotViewer::onExecute(RTC::UniqueId ec_id)
{
  unsigned int i,j;
  int setData = 0;
  int res;

  static std::string pec_prev;
  static std::string separate_prev;

  std::string cmd;
  std::string::size_type loc1;

  //aliases for InPort data
  const char* pNameShort = "short";
  const char* pNameLong = "long";
  const char* pNameFloat = "float";
  const char* pNameDouble = "double";
  const char* pNamePre = "[";
  const char* pNamePost = "]";

  std::vector< std::vector<int> > i_vect(m_ShortSeqDataIn.getSize() + m_LongSeqDataIn.getSize());
  std::vector< std::vector<double> > d_vect(m_FloatSeqDataIn.getSize() + m_DoubleSeqDataIn.getSize());

  // ******* get parameters from configuration variables *************************************** //
  // ------- get separate list --------------------------------------------- //
  if((m_gpSeparatePos != separate_prev || separate_list.empty()) && (m_ShortSeqDataIn.getSize()+m_LongSeqDataIn.getSize()+m_FloatSeqDataIn.getSize()+m_DoubleSeqDataIn.getSize()>0)){ //find new separate list
    //initialize list
    separate_list.clear();
    separate_prev = m_gpSeparatePos;

    //find separator
    if(separate_prev.find_first_not_of("1234567890:") != std::string::npos){ //if invalid characters are found
      std::cerr << "Invalid command: gpSeparatePos" << std::endl;
    }else{
      while(!separate_prev.empty()){
        loc1 = separate_prev.find_first_of(":"); //separator is ':'
        if(loc1 != std::string::npos){ //find separator
          if(loc1 != 0){
            separate_list.push_back(std::atoi(separate_prev.substr(0,loc1).c_str()));
          }else{
            separate_list.push_back(1);
          }
          separate_prev.erase(0,loc1+1);
        }else{
          separate_list.push_back(std::atoi(separate_prev.c_str()));
          break;
        }
      }
    }

    if(separate_list.size() < m_ShortSeqDataIn.getSize() + m_LongSeqDataIn.getSize() + m_FloatSeqDataIn.getSize() + m_DoubleSeqDataIn.getSize()){ //if list is not enough
      separate_list.resize(m_ShortSeqDataIn.getSize() + m_LongSeqDataIn.getSize() + m_FloatSeqDataIn.getSize() + m_DoubleSeqDataIn.getSize(),1); //add 1
    }else{
      separate_list.resize(m_ShortSeqDataIn.getSize() + m_LongSeqDataIn.getSize() + m_FloatSeqDataIn.getSize() + m_DoubleSeqDataIn.getSize());
    }

    std::cerr << "Set separate position list." << std::endl;
    separate_prev = m_gpSeparatePos;

    for(j=0;j<separate_list.size();j++){
      std::cerr << separate_list[j] << ' ';
    }
    std::cerr << std::endl;

  }


  // ------- get periodic exec commnand ------------------------------------ //
  if(m_gpPeriodicExecCommand != pec_prev || periodic_cmd.empty()){ //find new command
    if(m_gpPeriodicExecCommand.empty() || (m_gpPeriodicExecCommand == "*")){ //no command ("*": default message)
      pec_prev.clear();
      periodic_cmd.clear();
    }else{
      pec_prev = m_gpPeriodicExecCommand;
      periodic_cmd = pec_prev;
      std::cerr << "Set command: " << periodic_cmd << std::endl;
    }
  }

  // ******* get information from InPorts ****************************************************** //
  // ------- get new command from InPort ----------------------------------- //
  if(m_CommandIn.isNew()){  //new data comes
    m_CommandIn.read();
    cmd = m_Command.data;
    //send command to gnuplot
    if(!cmd.empty()){
      std::cerr << cmd << std::endl;

      //convert to tmp filename
      //short data
      convert_alias_to_filename(gp, cmd, pNameShort, pNamePre, pNamePost, 0, m_ShortSeqDataIn.getSize());
      //long data
      convert_alias_to_filename(gp, cmd, pNameLong, pNamePre, pNamePost, m_ShortSeqDataIn.getSize(), m_LongSeqDataIn.getSize());
      //float data
      convert_alias_to_filename(gp, cmd, pNameFloat, pNamePre, pNamePost, m_ShortSeqDataIn.getSize()+m_LongSeqDataIn.getSize(), m_FloatSeqDataIn.getSize());
      //double data
      convert_alias_to_filename(gp, cmd, pNameDouble, pNamePre, pNamePost, m_ShortSeqDataIn.getSize()+m_LongSeqDataIn.getSize()+m_FloatSeqDataIn.getSize(), m_DoubleSeqDataIn.getSize());

      gp.sendCommand(cmd.c_str());
    }
  }

  // ------- get new data from dynamic InPorts ----------------------------- //
  //short data
  for(i=0;i<m_ShortSeqDataIn.getSize();i++){
    if(m_ShortSeqDataIn.m_port[i].isNew()){  //new data comes
      //read data from InPort
      m_ShortSeqDataIn.m_port[i].read();
      i_vect[i].clear();

      for(j=0;j<m_ShortSeqDataIn.m_data[i].data.length();j++){
        i_vect[i].push_back(m_ShortSeqDataIn.m_data[i].data[j]);
      }

      res = gp.setData(i, i_vect[i], separate_list[i]);
      if(res==0){
        setData = 1;
      }
    }
  }

  //long data
  for(i=0;i<m_LongSeqDataIn.getSize();i++){
    if(m_LongSeqDataIn.m_port[i].isNew()){  //new data comes
      //read data from InPort
      m_LongSeqDataIn.m_port[i].read();
      i_vect[i+m_ShortSeqDataIn.getSize()].clear();

      for(j=0;j<m_LongSeqDataIn.m_data[i].data.length();j++){
        i_vect[i+m_ShortSeqDataIn.getSize()].push_back(m_LongSeqDataIn.m_data[i].data[j]);
      }

      res = gp.setData(i+m_ShortSeqDataIn.getSize(), i_vect[i+m_ShortSeqDataIn.getSize()], separate_list[i+m_ShortSeqDataIn.getSize()]);
      if(res==0){
        setData = 1;
      }
    }
  }

  //float data
  for(i=0;i<m_FloatSeqDataIn.getSize();i++){
    if(m_FloatSeqDataIn.m_port[i].isNew()){  //new data comes
      //read data from InPort
      m_FloatSeqDataIn.m_port[i].read();
      d_vect[i].clear();

      for(j=0;j<m_FloatSeqDataIn.m_data[i].data.length();j++){
        d_vect[i].push_back(m_FloatSeqDataIn.m_data[i].data[j]);
      }

      res = gp.setData(i+m_ShortSeqDataIn.getSize()+m_LongSeqDataIn.getSize(), d_vect[i], separate_list[i+m_ShortSeqDataIn.getSize()+m_LongSeqDataIn.getSize()]);
      if(res==0){
        setData = 1;
      }
    }
  }

  //double data
  for(i=0;i<m_DoubleSeqDataIn.getSize();i++){
    if(m_DoubleSeqDataIn.m_port[i].isNew()){  //new data comes
      //read data from InPort
      m_DoubleSeqDataIn.m_port[i].read();
      d_vect[i+m_FloatSeqDataIn.getSize()].clear();

      for(j=0;j<m_DoubleSeqDataIn.m_data[i].data.length();j++){
        d_vect[i+m_FloatSeqDataIn.getSize()].push_back(m_DoubleSeqDataIn.m_data[i].data[j]);
      }

      res = gp.setData(i+m_ShortSeqDataIn.getSize()+m_LongSeqDataIn.getSize()+m_FloatSeqDataIn.getSize(), d_vect[i+m_FloatSeqDataIn.getSize()], separate_list[i+m_ShortSeqDataIn.getSize()+m_LongSeqDataIn.getSize()+m_FloatSeqDataIn.getSize()]);
      if(res==0){
        setData = 1;
      }
    }
  }

  // ******* do periodic exec command *********************************** //
  if((!periodic_cmd.empty()) && (setData==1)){
    cmd = periodic_cmd;

    //convert to tmp filename
    //short data
    convert_alias_to_filename(gp, cmd, pNameShort, pNamePre, pNamePost, 0, m_ShortSeqDataIn.getSize());
    //long data
    convert_alias_to_filename(gp, cmd, pNameLong, pNamePre, pNamePost, m_ShortSeqDataIn.getSize(), m_LongSeqDataIn.getSize());
    //float data
    convert_alias_to_filename(gp, cmd, pNameFloat, pNamePre, pNamePost, m_ShortSeqDataIn.getSize()+m_LongSeqDataIn.getSize(), m_FloatSeqDataIn.getSize());
    //double data
    convert_alias_to_filename(gp, cmd, pNameDouble, pNamePre, pNamePost, m_ShortSeqDataIn.getSize()+m_LongSeqDataIn.getSize()+m_FloatSeqDataIn.getSize(), m_DoubleSeqDataIn.getSize());

    gp.sendCommand(cmd.c_str());
  }

  return RTC::RTC_OK;
}

/*!
 * 動的入力ポートの削除とgnuplotのクローズを行う。
 */

RTC::ReturnCode_t GnuplotViewer::onAborting(RTC::UniqueId ec_id)
{
  separate_list.clear();
  periodic_cmd.clear();

  gp.finalize();

  //delete port... put removePort first!!
  while(m_ShortSeqDataIn.getSize() > 0){
    removeInPort(m_ShortSeqDataIn.m_port[m_ShortSeqDataIn.getSize()-1]);
    m_ShortSeqDataIn.deletePort(m_ShortSeqDataIn.getSize()-1);
  }
  while(m_LongSeqDataIn.getSize() > 0){
    removeInPort(m_LongSeqDataIn.m_port[m_LongSeqDataIn.getSize()-1]);
    m_LongSeqDataIn.deletePort(m_LongSeqDataIn.getSize()-1);
  }
  while(m_FloatSeqDataIn.getSize() > 0){
    removeInPort(m_FloatSeqDataIn.m_port[m_FloatSeqDataIn.getSize()-1]);
    m_FloatSeqDataIn.deletePort(m_FloatSeqDataIn.getSize()-1);
  }
  while(m_DoubleSeqDataIn.getSize() > 0){
    removeInPort(m_DoubleSeqDataIn.m_port[m_DoubleSeqDataIn.getSize()-1]);
    m_DoubleSeqDataIn.deletePort(m_DoubleSeqDataIn.getSize()-1);
  }

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t GnuplotViewer::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GnuplotViewer::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GnuplotViewer::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GnuplotViewer::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void GnuplotViewerInit(RTC::Manager* manager)
  {
    coil::Properties profile(gnuplotviewer_spec);
    manager->registerFactory(profile,
                             RTC::Create<GnuplotViewer>,
                             RTC::Delete<GnuplotViewer>);
  }
  
};


