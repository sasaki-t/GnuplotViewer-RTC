# SinCosFunction

## Overview

Sine and cosine function generator

## Description

正弦波、余弦波を出力する。<br/>アクティブ化するとt=0に初期化され、x, sin(ks(x-cs*t)), cos(kc(x-cc*t)) (0<=x<2pi)のデータがOutPortに出力される。<br/>出力形式は、xData[0] sinData[0] cosData[0] xData[1] sinData[1] cosData[1] ... xData[SampleNum-1] sinData[SampleNum-1] cosData[SampleNum-1]の順。

### Input and Output

OutPort<br/>ポート名/型/説明<br/>XSinCosData/TimedDoubleSeq/x, sin(ks(x-cs*t)), cos(kc(x-cc*t))の値。出力形式は、xData[0] sinData[0] cosData[0] xData[1] sinData[1] cosData[1] ... xData[SampleNum-1] sinData[SampleNum-1] cosData[SampleNum-1]の順。

### Algorithm etc



### Basic Information

|  |  |
----|---- 
| Module Name | SinCosFunction |
| Description | Sine and cosine function generator |
| Version | 1.1.0 |
| Vendor | TakeshiSasaki |
| Category | generic |
| Comp. Type | STATIC |
| Act. Type | PERIODIC |
| Kind | DataFlowComponent |
| MAX Inst. | 1 |

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
      <td>初期化を行う。</td>
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
    <td>on_deactivated</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td rowspan="4">on_execute</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>x, sin(ks(x-cs*t)), cos(kc(x-cc*t)) (0<=x<2pi)のデータを出力する。</td>
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
    <td>on_aborting</td>
    <td colspan="2"></td>
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


### OutPorts definition

#### XSinCosData

x, sin(ks(x-cs*t)), cos(kc(x-cc*t))の値。<br/>出力形式は、xData[0] sinData[0] cosData[0] xData[1] sinData[1] cosData[1] ... xData[SampleNum-1] sinData[SampleNum-1] cosData[SampleNum-1]の順。

<table>
  <tr>
    <td>DataType</td>
    <td>RTC::TimedDoubleSeq</td>
    <td>TimedDoubleSeq</td>
  </tr>
  <tr>
    <td>IDL file</td>
    <td colspan="2">BasicDataType.idl</td>
  </tr>
  <tr>
    <td>Number of Data</td>
    <td colspan="2">3*SampleNum</td>
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


### Service Port definition


### Configuration definition

#### sWaveNum

正弦波の波数ks。<br/>単位はrad/m。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">double</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>1.0</td>
    <td>1.0</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td>rad/m</td>
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

#### sPhaseVel

正弦波の位相速度cs。<br/>単位はm/s。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">double</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>1.0</td>
    <td>1.0</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td>m/s</td>
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

#### cWaveNum

余弦波の波数kc。<br/>単位はrad/m。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">double</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>1.0</td>
    <td>1.0</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td>rad/m</td>
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

#### cPhaseVel

余弦波の位相速度cc。<br/>単位はm/s。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">double</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>1.0</td>
    <td>1.0</td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td>m/s</td>
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

#### SampleNum

データ数。<br/>[0,2pi)の範囲をこのデータ数でサンプルする。


<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">int</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>200</td>
    <td>200</td>
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
