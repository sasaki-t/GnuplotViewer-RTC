// -*- C++ -*-
/*!
 * @file  SinCosFunctionTest.h
 * @brief Sine and cosine function generator
 * @date  $Date$
 *
 * @author 佐々木毅 (Takeshi SASAKI)
 * sasaki-t(_at_)ieee.org
 *
 * $Id$
 */

#ifndef SINCOSFUNCTION_TEST__H
#define SINCOSFUNCTION_TEST_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">
#include "BasicDataTypeSVC_impl.h"

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="port_stub_h">
// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

using namespace RTC;

/*!
 * @class SinCosFunctionTest
 * @brief Sine and cosine function generator
 *
 * 正弦波、余弦波を出力する。
 * アクティブ化するとt=0に初期化され、x, sin(ks(x-cs*t)),
 * cos(kc(x-cc*t)) (0<=x<2pi)のデータがOutPortに出力される。
 * 出力形式は、xData[0] sinData[0] cosData[0] xData[1] sinData[1]
 * cosData[1] ... xData[SampleNum-1] sinData[SampleNum-1]
 * cosData[SampleNum-1]の順。
 *
 * OutPort
 * ポート名/型/説明
 * XSinCosData/TimedDoubleSeq/x, sin(ks(x-cs*t)),
 * cos(kc(x-cc*t))の値。出力形式は、xData[0] sinData[0]
 * cosData[0] xData[1] sinData[1] cosData[1] ...
 * xData[SampleNum-1] sinData[SampleNum-1]
 * cosData[SampleNum-1]の順。
 *
 */
class SinCosFunctionTest
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  SinCosFunctionTest(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~SinCosFunctionTest();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   * 初期化を行う。
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   * x, sin(ks(x-cs*t)), cos(kc(x-cc*t))
   * (0<=x<2pi)のデータを出力する。
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 正弦波の波数ks。
   * 単位はrad/m。
   * - Name: sWaveNum sWaveNum
   * - DefaultValue: 1.0
   * - Unit: rad/m
   */
  double m_sWaveNum;
  /*!
   * 正弦波の位相速度cs。
   * 単位はm/s。
   * - Name: sPhaseVel sPhaseVel
   * - DefaultValue: 1.0
   * - Unit: m/s
   */
  double m_sPhaseVel;
  /*!
   * 余弦波の波数kc。
   * 単位はrad/m。
   * - Name: cWaveNum cWaveNum
   * - DefaultValue: 1.0
   * - Unit: rad/m
   */
  double m_cWaveNum;
  /*!
   * 余弦波の位相速度cc。
   * 単位はm/s。
   * - Name: cPhaseVel cPhaseVel
   * - DefaultValue: 1.0
   * - Unit: m/s
   */
  double m_cPhaseVel;
  /*!
   * データ数。
   * [0,2pi)の範囲をこのデータ数でサンプルする。
   * - Name: SampleNum SampleNum
   * - DefaultValue: 200
   */
  int m_SampleNum;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::TimedDoubleSeq m_XSinCosData;
  /*!
   * x, sin(ks(x-cs*t)), cos(kc(x-cc*t))の値。
   * 出力形式は、xData[0] sinData[0] cosData[0] xData[1]
   * sinData[1] cosData[1] ... xData[SampleNum-1]
   * sinData[SampleNum-1] cosData[SampleNum-1]の順。
   * - Type: TimedDoubleSeq
   * - Number: 3*SampleNum
   */
  InPort<RTC::TimedDoubleSeq> m_XSinCosDataIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};


extern "C"
{
  DLL_EXPORT void SinCosFunctionTestInit(RTC::Manager* manager);
};

#endif // SINCOSFUNCTION_TEST_H
