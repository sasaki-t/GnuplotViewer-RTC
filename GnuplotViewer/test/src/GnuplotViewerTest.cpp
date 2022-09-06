// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  GnuplotViewerTest.cpp
 * @brief Versatile viewer component using gnuplot (test code)
 *
 * @author 佐々木毅 (Takeshi SASAKI)
 * sasaki-t(_at_)ieee.org
 *
 */
// </rtc-template>

#include "GnuplotViewerTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const gnuplotviewer_spec[] =
#else
static const char* gnuplotviewer_spec[] =
#endif
  {
    "implementation_id", "GnuplotViewerTest",
    "type_name",         "GnuplotViewerTest",
    "description",       "Versatile viewer component using gnuplot",
    "version",           "1.2.0",
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
GnuplotViewerTest::GnuplotViewerTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_CommandOut("Command", m_Command),
    m_ShortSeqDataOut("ShortSeqData", m_ShortSeqData),
    m_LongSeqDataOut("LongSeqData", m_LongSeqData),
    m_FloatSeqDataOut("FloatSeqData", m_FloatSeqData),
    m_DoubleSeqDataOut("DoubleSeqData", m_DoubleSeqData)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
GnuplotViewerTest::~GnuplotViewerTest()
{
}



RTC::ReturnCode_t GnuplotViewerTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("Command", m_CommandOut);
  addOutPort("ShortSeqData", m_ShortSeqDataOut);
  addOutPort("LongSeqData", m_LongSeqDataOut);
  addOutPort("FloatSeqData", m_FloatSeqDataOut);
  addOutPort("DoubleSeqData", m_DoubleSeqDataOut);
  
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
RTC::ReturnCode_t GnuplotViewerTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t GnuplotViewerTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t GnuplotViewerTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}

/*!
 * Configurationのp{Short,Long,Float,Double}InPortNumの値に応じて動
 * 的入力ポートの生成を行う。
 * また、gnuplotを起動する。
 * このとき、ConfigurationのgpOpenOptionにgnuplotの起動オプションが
 * 与えられていれば、そのオプションにしたがってgnuplotをオープンす
 * る。
 */

RTC::ReturnCode_t GnuplotViewerTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}

/*!
 * 動的入力ポートの削除とgnuplotのクローズを行う。
 */

RTC::ReturnCode_t GnuplotViewerTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}

/*!
 * InPortのCommandに送られてきたgnuplotのコマンドを実行する。
 * InPortの{Short,Long,Float,Double}SeqDataに送られてきたデータをC
 * onfigurationのgpSeparatePosの形式にしたがって保存する。
 * 新しいデータが入力される度にConfigurationのgpPeriodicExecComman
 * dに記入されたコマンドを実行する。
 */

RTC::ReturnCode_t GnuplotViewerTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}

/*!
 * 動的入力ポートの削除とgnuplotのクローズを行う。
 */

RTC::ReturnCode_t GnuplotViewerTest::onAborting(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t GnuplotViewerTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t GnuplotViewerTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t GnuplotViewerTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t GnuplotViewerTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool GnuplotViewerTest::runTest()
{
    return true;
}


extern "C"
{
 
  void GnuplotViewerTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(gnuplotviewer_spec);
    manager->registerFactory(profile,
                             RTC::Create<GnuplotViewerTest>,
                             RTC::Delete<GnuplotViewerTest>);
  }
  
}
