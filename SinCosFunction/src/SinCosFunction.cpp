// -*- C++ -*-
/*!
 * @file  SinCosFunction.cpp
 * @brief Sine and cosine function generator
 * @date $Date$
 *
 * @author 佐々木毅 (Takeshi SASAKI)
 * sasaki-t(_at_)ieee.org
 *
 * $Id$
 */
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES //for M_PI

#include "SinCosFunction.h"

// Module specification
// <rtc-template block="module_spec">
static const char* sincosfunction_spec[] =
  {
    "implementation_id", "SinCosFunction",
    "type_name",         "SinCosFunction",
    "description",       "Sine and cosine function generator",
    "version",           "1.0.0",
    "vendor",            "TakeshiSasaki",
    "category",          "generic",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
	// Configuration variables
    "conf.default.sWaveNum", "1.0",
    "conf.default.sPhaseVel", "1.0",
    "conf.default.cWaveNum", "1.0",
    "conf.default.cPhaseVel", "1.0",
    "conf.default.SampleNum", "200",

    // Widget
    "conf.__widget__.sWaveNum", "text",
    "conf.__widget__.sPhaseVel", "text",
    "conf.__widget__.cWaveNum", "text",
    "conf.__widget__.cPhaseVel", "text",
    "conf.__widget__.SampleNum", "text",
    // Constraints

    "conf.__type__.sWaveNum", "double",
    "conf.__type__.sPhaseVel", "double",
    "conf.__type__.cWaveNum", "double",
    "conf.__type__.cPhaseVel", "double",
    "conf.__type__.SampleNum", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
SinCosFunction::SinCosFunction(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_XSinCosDataOut("XSinCosData", m_XSinCosData)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SinCosFunction::~SinCosFunction()
{
}



RTC::ReturnCode_t SinCosFunction::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("XSinCosData", m_XSinCosDataOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("sWaveNum", m_sWaveNum, "1.0");
  bindParameter("sPhaseVel", m_sPhaseVel, "1.0");
  bindParameter("cWaveNum", m_cWaveNum, "1.0");
  bindParameter("cPhaseVel", m_cPhaseVel, "1.0");
  bindParameter("SampleNum", m_SampleNum, "200");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SinCosFunction::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunction::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunction::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*!
 * 初期化を行う。
 */

RTC::ReturnCode_t SinCosFunction::onActivated(RTC::UniqueId ec_id)
{
  t0 = coil::gettimeofday();

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SinCosFunction::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*!
 * x, sin(ks(x-cs*t)), cos(kc(x-cc*t))
 * (0<=x<2pi)のデータを出力する。
 */

RTC::ReturnCode_t SinCosFunction::onExecute(RTC::UniqueId ec_id)
{
  int i;
  double x, t;

  //wave number
  double ks = m_sWaveNum;
  double kc = m_cWaveNum;

  //phase velocity
  double cs = m_sPhaseVel;
  double cc = m_cPhaseVel;

  //data num
  int data_num = m_SampleNum;

  if (data_num <= 0) {
    std::cerr << "Invalid parameter: SampleNum" << std::endl;
    return RTC::RTC_OK;
  }

  //set data num
  m_XSinCosData.data.length(3 * data_num);

  //get time stamp
  coil::TimeValue tv = coil::gettimeofday();
  m_XSinCosData.tm.sec = tv.sec();
  m_XSinCosData.tm.nsec = 1000 * tv.usec();

  t = (double)(tv.sec() - t0.sec()) + (double)(tv.usec() - t0.usec()) / 1000000.0;

  for (i = 0; i < data_num; i++) {
    x = (double)2 * M_PI * i / data_num;

    m_XSinCosData.data[3 * i] = x;
    m_XSinCosData.data[3 * i + 1] = std::sin(ks*(x - cs * t));
    m_XSinCosData.data[3 * i + 2] = std::cos(kc*(x - cc * t));
  }
  m_XSinCosDataOut.write();

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SinCosFunction::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunction::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunction::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunction::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunction::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SinCosFunctionInit(RTC::Manager* manager)
  {
    coil::Properties profile(sincosfunction_spec);
    manager->registerFactory(profile,
                             RTC::Create<SinCosFunction>,
                             RTC::Delete<SinCosFunction>);
  }
  
};


