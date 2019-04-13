// -*- C++ -*-
/*!
 * @file  GnuplotViewerTest.h
 * @brief Versatile viewer component using gnuplot
 * @date  $Date$
 *
 * @author 佐々木毅 (Takeshi SASAKI)
 * sasaki-t(_at_)ieee.org
 *
 * $Id$
 */

#ifndef GNUPLOTVIEWER_TEST__H
#define GNUPLOTVIEWER_TEST_H

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
 * @class GnuplotViewerTest
 * @brief Versatile viewer component using gnuplot
 *
 * gnuplotを用いた汎用ビューワ。
 * Configurationのp{Short,Long,Float,Double}InPortNumの値を設定して
 * アクティブ化すると対応する入力ポートがその数だけ生成されるととも
 * にgnuplotを起動する。
 * このとき、ConfigurationのgpOpenOptionにgnuplotの起動オプションが
 * 与えられていれば、そのオプションにしたがってgnuplotをオープンす
 * る。
 * アクティブ化後は新しいデータが入力される度にConfigurationのgpPe
 * riodicExecCommandに記入されたコマンドを実行する。
 * InPortから入力されたデータは例えば3つ目のshort型ポートへのデータ
 * であれば"short[2]"、最初のlong型ポートへのデータであれば"long[0
 * ]"で参照できる。
 * また、InPortのCommandからgnuplotにコマンドを送ることも可能である
 * 。
 *
 * InPort
 * ポート名/型/説明
 * Command/TimedString/gnuplotに送るコマンド。
 * ShortSeqData/DynamicInPort<TimedShortSeq>/プロットするshort型整
 * 数値列データ。
 * LongSeqData/DynamicInPort<TimedLongSeq>/プロットするlong型整数値
 * 列データ。
 * FloatSeqData/DynamicInPort<TimedFloatSeq>/プロットするfloat型実
 * 数値列データ。
 * DoubleSeqData/DynamicInPort<TimedDoubleSeq>/プロットするdouble型
 * 実数値列データ。
 *
 */
class GnuplotViewerTest
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  GnuplotViewerTest(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~GnuplotViewerTest();

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
   * Configurationのp{Short,Long,Float,Double}InPortNumの値に応じて
   * 動的入力ポートの生成を行う。
   * また、gnuplotを起動する。
   * このとき、ConfigurationのgpOpenOptionにgnuplotの起動オプション
   * が与えられていれば、そのオプションにしたがってgnuplotをオープ
   * ンする。
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
   * 動的入力ポートの削除とgnuplotのクローズを行う。
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
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   * InPortのCommandに送られてきたgnuplotのコマンドを実行する。
   * InPortの{Short,Long,Float,Double}SeqDataに送られてきたデータを
   * ConfigurationのgpSeparatePosの形式にしたがって保存する。
   * 新しいデータが入力される度にConfigurationのgpPeriodicExecComm
   * andに記入されたコマンドを実行する。
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
   * 動的入力ポートの削除とgnuplotのクローズを行う。
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
   virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

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
   * gnuplotを開く際のオプション。
   * アクティブ化時に読み込みを行う。
   * デフォルト値の場合は、オプションなしで開く。
   * アクティブ状態での変更は無効（反映されない）。
   * - Name: gpOpenOption gpOpenOption
   * - DefaultValue: *
   */
  std::string m_gpOpenOption;
  /*!
   * データの区切り位置のリスト。
   * コロン(:)を区切り文字として指定する。(例 4:2:3)
   * 指定されなかったポートの値は1となる。
   * - Name: gpSeparatePos gpSeparatePos
   * - DefaultValue: 1
   */
  std::string m_gpSeparatePos;
  /*!
   * gnuplotが周期実行するコマンド。
   * コンポーネントに新しいデータが入力される度に実行される。
   * デフォルト値の場合は何も実行しない。
   * - Name: gpPeriodicExecCommand gpPeriodicExecCommand
   * - DefaultValue: *
   */
  std::string m_gpPeriodicExecCommand;
  /*!
   * TimedShortSeq型InPortのポート数。
   * アクティブ状態での変更は無効（反映されない）。
   * - Name: pShortInPortNum pShortInPortNum
   * - DefaultValue: 0
   * - Constraint: x>=0
   */
  int m_pShortInPortNum;
  /*!
   * TimedLongSeq型InPortのポート数。
   * アクティブ状態での変更は無効（反映されない）。
   * - Name: pLongInPortNum pLongInPortNum
   * - DefaultValue: 0
   * - Constraint: x>=0
   */
  int m_pLongInPortNum;
  /*!
   * TimedFloatSeq型InPortのポート数。
   * アクティブ状態での変更は無効（反映されない）。
   * - Name: pFloatInPortNum pFloatInPortNum
   * - DefaultValue: 0
   * - Constraint: x>=0
   */
  int m_pFloatInPortNum;
  /*!
   * TimedDoubleSeq型InPortのポート数。
   * アクティブ状態での変更は無効（反映されない）。
   * - Name: pDoubleInPortNum pDoubleInPortNum
   * - DefaultValue: 0
   * - Constraint: x>=0
   */
  int m_pDoubleInPortNum;
  /*!
   * gnuplotへのパス。
   * デフォルト値の場合はカレントフォルダから開く。（環境変数にすで
   * にパスが指定されているなど、カレントフォルダからgnuplotを開け
   * る場合はデフォルトのままでよい。）
   * アクティブ状態での変更は無効（反映されない）。
   * - Name: gpPath gpPath
   * - DefaultValue: *
   */
  std::string m_gpPath;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedString m_Command;
  /*!
   * gnuplotに送るコマンド。
   * - Type: TimedString
   */
  OutPort<RTC::TimedString> m_CommandOut;
  RTC::TimedShortSeq m_ShortSeqData;
  /*!
   * プロットするshort型整数値列データ。
   * - Type: DynamicInPort<TimedShortSeq>
   * - Number: データに依存
   * - Unit: データに依存
   */
  OutPort<RTC::TimedShortSeq> m_ShortSeqDataOut;
  RTC::TimedLongSeq m_LongSeqData;
  /*!
   * プロットするlong型整数値列データ。
   * - Type: DynamicInPort<TimedLongSeq>
   * - Number: データに依存
   * - Unit: データに依存
   */
  OutPort<RTC::TimedLongSeq> m_LongSeqDataOut;
  RTC::TimedFloatSeq m_FloatSeqData;
  /*!
   * プロットするfloat型実数値列データ。
   * - Type: DynamicInPort<TimedFloatSeq>
   * - Number: データに依存
   * - Unit: データに依存
   */
  OutPort<RTC::TimedFloatSeq> m_FloatSeqDataOut;
  RTC::TimedDoubleSeq m_DoubleSeqData;
  /*!
   * プロットするdouble型実数値列データ。
   * - Type: DynamicInPort<TimedDoubleSeq>
   * - Number: データに依存
   * - Unit: データに依存
   */
  OutPort<RTC::TimedDoubleSeq> m_DoubleSeqDataOut;
  
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
  DLL_EXPORT void GnuplotViewerTestInit(RTC::Manager* manager);
};

#endif // GNUPLOTVIEWER_TEST_H
