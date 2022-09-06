# GnuplotViewer

## Overview

Versatile viewer component using gnuplot

## Description

gnuplotを用いた汎用ビューワ。<br/>Configurationのp{Short,Long,Float,Double}InPortNumの値を設定してアクティブ化すると対応する入力ポートがその数だけ生成されるとともにgnuplotを起動する。<br/>このとき、ConfigurationのgpOpenOptionにgnuplotの起動オプションが与えられていれば、そのオプションにしたがってgnuplotをオープンする。<br/>アクティブ化後は新しいデータが入力される度にConfigurationのgpPeriodicExecCommandに記入されたコマンドを実行する。<br/>InPortから入力されたデータは例えば3つ目のshort型ポートへのデータであれば"short[2]"、最初のlong型ポートへのデータであれば"long[0]"で参照できる。<br/>また、InPortのCommandからgnuplotにコマンドを送ることも可能である。

### Input and Output

InPort<br/>ポート名/型/説明<br/>Command/TimedString/gnuplotに送るコマンド。<br/>ShortSeqData/DynamicInPort<TimedShortSeq>/プロットするshort型整数値列データ。<br/>LongSeqData/DynamicInPort<TimedLongSeq>/プロットするlong型整数値列データ。<br/>FloatSeqData/DynamicInPort<TimedFloatSeq>/プロットするfloat型実数値列データ。<br/>DoubleSeqData/DynamicInPort<TimedDoubleSeq>/プロットするdouble型実数値列データ。

### Algorithm etc



### Basic Information

|  |  |
----|---- 
| Module Name | GnuplotViewer |
| Description | Versatile viewer component using gnuplot |
| Version | 1.2.0 |
| Vendor | TakeshiSasaki |
| Category | generic |
| Comp. Type | COMMUTATIVE |
| Act. Type | PERIODIC |
| Kind | DataFlowComponent |
| MAX Inst. | 0 |

### Activity definition

<table>
  <tr>
    <td rowspan="4">on_initialize</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td></td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td></td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td></td>
    </tr>
  </tr>
  <tr>
    <td>on_finalize</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_startup</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_shutdown</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td rowspan="4">on_activated</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>Configurationのp{Short,Long,Float,Double}InPortNumの値に応じて動的入力ポートの生成を行う。<br/>また、gnuplotを起動する。<br/>このとき、ConfigurationのgpOpenOptionにgnuplotの起動オプションが与えられていれば、そのオプションにしたがってgnuplotをオープンする。</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td></td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td></td>
    </tr>
  </tr>
  <tr>
    <td rowspan="4">on_deactivated</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>動的入力ポートの削除とgnuplotのクローズを行う。</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td></td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td></td>
    </tr>
  </tr>
  <tr>
    <td rowspan="4">on_execute</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>InPortのCommandに送られてきたgnuplotのコマンドを実行する。<br/>InPortの{Short,Long,Float,Double}SeqDataに送られてきたデータをConfigurationのgpSeparatePosの形式にしたがって保存する。<br/>新しいデータが入力される度にConfigurationのgpPeriodicExecCommandに記入されたコマンドを実行する。</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td></td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td></td>
    </tr>
  </tr>
  <tr>
    <td rowspan="4">on_aborting</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>動的入力ポートの削除とgnuplotのクローズを行う。</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td></td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td></td>
    </tr>
  </tr>
  <tr>
    <td>on_error</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_reset</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_state_update</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_rate_changed</td>
    <td colspan="2"></td>
  </tr>
</table>

### InPorts definition

#### Command

gnuplotに送るコマンド。

<table>
  <tr>
    <td>DataType</td>
    <td>RTC::TimedString</td>
    <td>TimedString</td>
  </tr>
  <tr>
    <td>IDL file</td>
    <td colspan="2">BasicDataType.idl</td>
  </tr>
  <tr>
    <td>Number of Data</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Semantics</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Occirrence frecency Period</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Operational frecency Period</td>
    <td colspan="2"></td>
  </tr>
</table>

#### ShortSeqData

プロットするshort型整数値列データ。

<table>
  <tr>
    <td>DataType</td>
    <td>RTC::TimedShortSeq</td>
    <td>DynamicInPort<TimedShortSeq></td>
  </tr>
  <tr>
    <td>IDL file</td>
    <td colspan="2">BasicDataType.idl</td>
  </tr>
  <tr>
    <td>Number of Data</td>
    <td colspan="2">データに依存</td>
  </tr>
  <tr>
    <td>Semantics</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td colspan="2">データに依存</td>
  </tr>
  <tr>
    <td>Occirrence frecency Period</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Operational frecency Period</td>
    <td colspan="2"></td>
  </tr>
</table>

#### LongSeqData

プロットするlong型整数値列データ。

<table>
  <tr>
    <td>DataType</td>
    <td>RTC::TimedLongSeq</td>
    <td>DynamicInPort<TimedLongSeq></td>
  </tr>
  <tr>
    <td>IDL file</td>
    <td colspan="2">BasicDataType.idl</td>
  </tr>
  <tr>
    <td>Number of Data</td>
    <td colspan="2">データに依存</td>
  </tr>
  <tr>
    <td>Semantics</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td colspan="2">データに依存</td>
  </tr>
  <tr>
    <td>Occirrence frecency Period</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Operational frecency Period</td>
    <td colspan="2"></td>
  </tr>
</table>

#### FloatSeqData

プロットするfloat型実数値列データ。

<table>
  <tr>
    <td>DataType</td>
    <td>RTC::TimedFloatSeq</td>
    <td>DynamicInPort<TimedFloatSeq></td>
  </tr>
  <tr>
    <td>IDL file</td>
    <td colspan="2">BasicDataType.idl</td>
  </tr>
  <tr>
    <td>Number of Data</td>
    <td colspan="2">データに依存</td>
  </tr>
  <tr>
    <td>Semantics</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td colspan="2">データに依存</td>
  </tr>
  <tr>
    <td>Occirrence frecency Period</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Operational frecency Period</td>
    <td colspan="2"></td>
  </tr>
</table>

#### DoubleSeqData

プロットするdouble型実数値列データ。

<table>
  <tr>
    <td>DataType</td>
    <td>RTC::TimedDoubleSeq</td>
    <td>DynamicInPort<TimedDoubleSeq></td>
  </tr>
  <tr>
    <td>IDL file</td>
    <td colspan="2">BasicDataType.idl</td>
  </tr>
  <tr>
    <td>Number of Data</td>
    <td colspan="2">データに依存</td>
  </tr>
  <tr>
    <td>Semantics</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td colspan="2">データに依存</td>
  </tr>
  <tr>
    <td>Occirrence frecency Period</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Operational frecency Period</td>
    <td colspan="2"></td>
  </tr>
</table>


### OutPorts definition


### Service Port definition


### Configuration definition

#### gpOpenOption

gnuplotを開く際のオプション。<br/>アクティブ化時に読み込みを行う。<br/>デフォルト値の場合は、オプションなしで開く。<br/>アクティブ状態での変更は無効（反映されない）。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">string</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>*</td>
    <td>*</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">text</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>

#### gpSeparatePos

データの区切り位置のリスト。<br/>コロン(:)を区切り文字として指定する。(例 4:2:3)<br/>指定されなかったポートの値は1となる。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">string</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>1</td>
    <td>1</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">text</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>

#### gpPeriodicExecCommand

gnuplotが周期実行するコマンド。<br/>コンポーネントに新しいデータが入力される度に実行される。<br/>デフォルト値の場合は何も実行しない。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">string</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>*</td>
    <td>*</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">text</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>

#### pShortInPortNum

TimedShortSeq型InPortのポート数。<br/>アクティブ状態での変更は無効（反映されない）。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">int</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>0</td>
    <td>0</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">text</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td>x>=0</td>
    <td>x>=0</td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>

#### pLongInPortNum

TimedLongSeq型InPortのポート数。<br/>アクティブ状態での変更は無効（反映されない）。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">int</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>0</td>
    <td>0</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">text</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td>x>=0</td>
    <td>x>=0</td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>

#### pFloatInPortNum

TimedFloatSeq型InPortのポート数。<br/>アクティブ状態での変更は無効（反映されない）。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">int</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>0</td>
    <td>0</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">text</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td>x>=0</td>
    <td>x>=0</td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>

#### pDoubleInPortNum

TimedDoubleSeq型InPortのポート数。<br/>アクティブ状態での変更は無効（反映されない）。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">int</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>0</td>
    <td>0</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">text</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td>x>=0</td>
    <td>x>=0</td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>

#### gpPath

gnuplotへのパス。<br/>デフォルト値の場合はカレントフォルダから開く。（環境変数にすでにパスが指定されているなど、カレントフォルダからgnuplotを開ける場合はデフォルトのままでよい。）<br/>アクティブ状態での変更は無効（反映されない）。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">string</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>*</td>
    <td>*</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">text</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>


## Demo

## Requirement

## Setup

### Windows

### Ubuntu

## Usage

## Running the tests

## LICENCE




## References




## Author

佐々木毅 (Takeshi SASAKI)<br/>sasaki-t(_at_)ieee.org
