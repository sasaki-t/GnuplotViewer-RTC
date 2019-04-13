// -*- C++ -*-
/*!
 * @file  SinCosFunctionTest.cpp
 * @brief Sine and cosine function generator
 * @date $Date$
 *
 * @author 佐々木毅 (Takeshi SASAKI)
 * sasaki-t(_at_)ieee.org
 *
 * $Id$
 */

#include "SinCosFunctionTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* sincosfunction_spec[] =
  {
    "implementation_id", "SinCosFunctionTest",
    "type_name",         "SinCosFunctionTest",
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
SinCosFunctionTest::SinCosFunctionTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_XSinCosDataOut("XSinCosData", m_XSinCosData)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SinCosFunctionTest::~SinCosFunctionTest()
{
}



RTC::ReturnCode_t SinCosFunctionTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("XSinCosData", m_XSinCosDataIn);
  
  // Set OutPort buffer
  
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
RTC::ReturnCode_t SinCosFunctionTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunctionTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunctionTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*!
 * 初期化を行う。
 */

RTC::ReturnCode_t SinCosFunctionTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SinCosFunctionTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*!
 * x, sin(ks(x-cs*t)), cos(kc(x-cc*t))
 * (0<=x<2pi)のデータを出力する。
 */

RTC::ReturnCode_t SinCosFunctionTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SinCosFunctionTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunctionTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunctionTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunctionTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SinCosFunctionTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SinCosFunctionTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(sincosfunction_spec);
    manager->registerFactory(profile,
                             RTC::Create<SinCosFunctionTest>,
                             RTC::Delete<SinCosFunctionTest>);
  }
  
};


