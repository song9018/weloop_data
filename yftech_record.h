//运动gps信息记录
///////////////////////////////////////////////////////////////////////////////////////////////////
typedef __packed struct
{
    uint16_t tag: 4; 
    uint16_t speed_value:11; 
	uint16_t speed_type:1; 
	
    int32_t lon;
    int32_t lat;
	uint16_t altitude;
	int32_t utc;
}record_gps_head_t;//16byte
STATIC_ASSERT(sizeof(record_gps_head_t) == 16);

typedef __packed struct
{
    uint16_t tag: 4; 
    uint16_t speed_value:11; 
	uint16_t speed_type:1; 
	
    int16_t lon;     //差值
    int16_t lat;    //差值
	uint8_t altitude;   //差值
    uint8_t utc; //差值
}record_gps_diff_t; //8byte
STATIC_ASSERT(sizeof(record_gps_diff_t) == 8);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//运动周期记录数据: 步频 步长 心率、心率可信度等
typedef __packed struct
{
  uint8_t tag:4;
  uint8_t cadence_type:3;//
  uint8_t cadence_tag:1;
  
  uint8_t sport_type:2; //
  uint8_t none:2; //
  uint8_t sport_state:4;
  
  uint32_t utc;       //
  
  uint8_t interval;  //
  uint8_t reserve[9];
}peroid_time_t;//16byte ----开始时间戳

typedef __packed struct
{
	
  uint8_t tag:4;
  uint8_t cadence_type:3;//
  uint8_t cadence_tag:1;
  
  uint8_t value_valid_num:4;
  uint8_t reverse:4;
  
  uint8_t data[14];
}peroid_step_t;//16byte

typedef __packed struct
{
  uint8_t tag:4;
  uint8_t cadence_type:3;//
  uint8_t cadence_tag:1;
  
  uint8_t value_valid_num:4;
  uint8_t reverse:4;
  
  uint8_t data[14];
}peroid_step_len_t;//16byte


typedef __packed struct
{
  uint8_t tag:4;
  uint8_t cadence_type:3;//
  uint8_t cadence_tag:1;
  
  uint8_t value_valid_num:4;
  uint8_t reverse:4;
  
  uint8_t data[14];
}peroid_heartrate_t;//16byte

typedef __packed struct
{
  uint8_t tag:4;
  uint8_t cadence_type:3;//
  uint8_t cadence_tag:1;
  
  uint8_t value_valid_num:4;
  uint8_t reverse:4;
  
  uint8_t data[14];//14*8/2=56
}peroid_trust_level_t;//16byte 心率可信度0~3 2bit



//////////////////////////////////////////////////////////////////////////////////////////////////////////
//运动标签记录
typedef __packed struct{
  uint32_t start_utc;           //开始记录时间戳
  uint8_t  metric_inch;         //当前运动公英制 //0:公制 1:英制
  int8_t  time_zone;            //当前运动时区
  uint32_t lap_distance_setting;//单圈距离设置 公制cm
  uint8_t reverse[4];          //保留
}sport_start_info_t; //14+2
STATIC_ASSERT(sizeof(sport_start_info_t) == 14);

typedef __packed struct{
  uint32_t stop_utc;      //停止时间戳
  uint8_t save_flag;      //0:丢弃数据 1:保存数据
  uint8_t reverse[9];     //保留
}sport_stop_info_t;//14+2
STATIC_ASSERT(sizeof(sport_stop_info_t) == 14);

typedef __packed struct{
  uint32_t pause_utc;      //暂停运动间戳
  uint8_t reverse[10];     //保留
}sport_pause_info_t;//14+2

STATIC_ASSERT(sizeof(sport_pause_info_t) == 14);

typedef __packed struct{
  uint32_t resume_utc;     //恢复运动间戳
  uint8_t reverse[10];     //保留
}sport_resume_info_t;//14+2
STATIC_ASSERT(sizeof(sport_resume_info_t) == 14);

typedef __packed struct{
	uint32_t current_utc;      //单圈记录时间戳
  uint8_t lap_index;         //单圈序号
	uint32_t lap_duration;     //单圈活动时间
  uint32_t lap_distance;     //单圈活动距离cm(除最后一圈外都等于单圈距离)
  
  uint32_t lap_step;         //单圈活动步数
  uint32_t lap_kcal;	       //单圈活动卡路里 小卡
  uint8_t lap_avg_cadence;   //单圈平均步频
  uint8_t lap_avg_heartrate; //单圈平均心率 
  
  uint8_t reverse[11];        //保留
}lap_run_info_t;//34+2
STATIC_ASSERT(sizeof(lap_run_info_t) == 34);

typedef __packed struct{
	uint32_t current_utc;      //单圈记录时间戳
  uint8_t lap_index;         //单圈序号
	uint32_t lap_duration;     //单圈活动时间  
  uint32_t lap_distance;     //单圈活动距离cm(除最后一圈外都等于单圈距离)

  uint32_t lap_kcal;	       //单圈活动卡路里 小卡
  uint8_t lap_avg_cadence;   //单圈平均踏频
  uint8_t lap_avg_heartrate; //单圈平均心率
  uint16_t lap_avg_power;    //单圈平均功率
  
  uint8_t reverse[13];        //保留
}lap_bicycle_info_t; //34+2

STATIC_ASSERT(sizeof(lap_bicycle_info_t) == 34);

typedef __packed struct{
	uint32_t current_utc;      //单圈记录时间戳
  uint8_t lap_index;         //单圈序号
	uint32_t lap_duration;     //单圈活动时间
  uint32_t lap_distance;     //单圈活动距离cm(除最后一圈外都等于单圈距离)
  
  uint16_t lap_pace;         //单圈配速(游泳的配速由算法计算)
  uint8_t lap_swim_type;     //单圈泳姿
  uint16_t lap_stroke;       //单圈划水次数  
  uint32_t lap_kcal;	       //单圈活动卡路里 小卡
  uint8_t lap_avg_heartrate; //单圈平均心率
  
  uint8_t reverse[11];        //保留
}lap_swim_info_t; //34+2
STATIC_ASSERT(sizeof(lap_swim_info_t) == 34);

typedef __packed struct{
  uint32_t total_distance;      //当前活动总距离cm
  uint32_t sport_duration;      //活动总时间 = stop_utc - start_utc - 暂停时间
  uint8_t  total_lap_num;       //活动总圈数(包括最后半圈)
  uint32_t total_kcal;          //活动总卡路里 小卡
  uint8_t  avg_heartrate;       //活动平均心率  
  uint32_t hrm_vo2max;          //活动最大摄氧量  
  
  uint8_t  avg_cadence;         //活动平均步频
  uint32_t total_step;          //活动总步数    
  uint16_t  total_elevation;    //活动总上升高度m
  uint16_t  total_decline;      //活动总下降高度m  
  
  uint16_t  avg_step_len;        //平均步长
  uint16_t max_cadence;         //最大步频
  uint8_t max_heartrate;        //最大心率
  uint8_t min_heartrate;        //最小心率
  uint16_t max_pace;            //最大配速
  uint16_t avg_pace;            //平均配速
   
  uint8_t reverse[9];           //保留
}sport_run_summary_info1_t; //46+2Byte
STATIC_ASSERT(sizeof(sport_run_summary_info1_t) == 46);

typedef __packed struct{
  uint32_t total_distance;      //当前活动总距离cm
  uint32_t sport_duration;      //活动总时间 = stop_utc - start_utc - 暂停时间
  uint8_t  total_lap_num;       //活动总圈数(包括最后半圈)
  uint32_t total_kcal;          //活动总卡路里 小卡
  uint8_t  avg_heartrate;       //活动平均心率  
  uint32_t hrm_vo2max;          //活动最大摄氧量  
  
  uint32_t total_stroke;        //活动总划水数
  
  uint16_t max_pace;            //最大配速
  uint16_t avg_pace;            //平均配速
  uint8_t max_strk_rate_len;    //最大单趟划水率
  uint8_t avg_strk_rate_len;    //平均单趟划水率
  uint16_t max_swolf_len;       //最大swolf
  uint16_t avg_swolf_len;       //平均swolf 
  
  uint8_t reverse[14];           //保留
}sport_swim_summary_info1_t; //46+2Byte
STATIC_ASSERT(sizeof(sport_swim_summary_info1_t) == 46);

typedef __packed struct{
  uint32_t total_distance;      //当前活动总距离cm
  uint32_t sport_duration;      //活动总时间 = stop_utc - start_utc - 暂停时间
  uint8_t  total_lap_num;       //活动总圈数(包括最后半圈)
  uint32_t total_kcal;          //活动总卡路里 小卡
  uint8_t  avg_heartrate;       //活动平均心率  
  uint32_t hrm_vo2max;          //活动最大摄氧量  
  
  uint8_t  avg_cadence;         //活动平均踏频
  uint16_t lap_avg_power;       //活动平均功率
  
  uint16_t  total_elevation;    //活动总上升高度m
  uint16_t  total_decline;      //活动总下降高度m
  
  uint16_t max_cadence;         //最大踏频
  uint8_t max_heartrate;        //最大心率
  uint8_t min_heartrate;        //最小心率
  uint16_t max_speed;           //最大速度*100
  uint16_t avg_speed;           //平均速度*100
   
  uint8_t reverse[13];           //保留
}sport_bicycle_summary_info1_t; //46+2Byte
STATIC_ASSERT(sizeof(sport_bicycle_summary_info1_t) == 46);

typedef __packed struct
{
    uint8_t tag: 4;         //记录标签
    uint8_t num:4;          //size=num*mtu 
   
    uint8_t sport_type: 4;  //运动类型 SPORT_TYPE_XX
    uint8_t sport_state: 4; //运动状态 SPORT_STATUS_XX

    __packed union
    {
       sport_start_info_t start;   //开始运动信息
       sport_stop_info_t stop;     //结束运动信息
       sport_pause_info_t pause;   //暂停运动信息
       sport_resume_info_t resume; //恢复运动信息
      
       lap_run_info_t lap_run;         //跑步单圈信息
       lap_swim_info_t lap_swim;       //游泳单圈信息
       lap_bicycle_info_t lap_bicycle; //自行车单圈信息
      
       sport_run_summary_info1_t run_summary1;         //跑步运动详情1
       sport_swim_summary_info1_t swim_summary1;       //游泳运动详情1
       sport_bicycle_summary_info1_t bicycle_summary1; //自行车运动详情1
       //...
    } u;
} record_sportinfo_t; //size=num*mtu

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//日常活动数据
typedef __packed struct{
  uint8_t tag: 4; 
  uint8_t num:4; 
  uint32_t current_utc; 
  int8_t current_zone;  
}record_time_t;//6byte 同步时间时区

STATIC_ASSERT(sizeof(record_time_t) == 6);

typedef __packed struct{
  uint32_t tag: 4; 
  uint32_t num:4;  
  
  uint32_t utc_minute:24;  
  uint32_t heartrate:8; 
  uint32_t reverse:8; 
}record_heartrate_minite_t;//6byte 日常计步分钟数据 10分钟一次
STATIC_ASSERT(sizeof(record_heartrate_minite_t) == 6);

typedef __packed struct{
  uint32_t tag: 4; 
  uint32_t num:4; 
  
  uint32_t utc_start_minute:24;    //活动统计开始时间
  uint32_t utc_end_minute:24;      //活动统计结束时间
  
  uint32_t exercise_duration:10;  //活动时间s 最大15*60s
  uint32_t exercise_cal:18;   //活动卡路里cal    
  uint32_t exercise_step:12;  //活动总步数 
}record_exercise_t;//12byte 活动统计数据, 切换时区时先保存数据再保存时区 5分钟保存一次
STATIC_ASSERT(sizeof(record_exercise_t) == 12);

typedef __packed struct{
  uint32_t tag: 4; //记录标签
  uint32_t num:4;  
  
  uint32_t step:10; 
  uint32_t cal:14;
}record_minute_step_t;//4byte 日常计步分钟扩展数据 2分钟一次
STATIC_ASSERT(sizeof(record_minute_step_t) == 4);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//日常气压信息 5秒一条
typedef __packed struct
{
    uint8_t tag: 4;     //记录标记
    uint8_t num: 4;
  
    uint16_t pressure; //气压
    int8_t tempc;      //温度
} pressure_record_t;
STATIC_ASSERT(sizeof(pressure_record_t) == 4);

//日常运动信息 一分钟记录一次, 0点清零
typedef __packed struct
{
    uint8_t tag: 4;      //记录标记
    uint8_t num: 4;
  
    uint8_t  week: 4;    //周几
    uint8_t  update: 1;  //数据变化需要刷新界面
    uint8_t  save: 1;    //数据变化需要存储  
    uint8_t  reserve: 2; 

    uint32_t step;       //当天步数
    uint32_t calorie;    //当天卡路里cal
    uint32_t distance;   //当天运动距离cm
    uint32_t duration;   //当天运动时长s 
    
    uint16_t exercise_time; //单位时间内的活动时间
    uint16_t exercise_step; //单位时间内的活动步数
    uint32_t exercise_calorie; //单位时间内的活动卡路里
    uint32_t exercise_start_utc;
  
    uint32_t floor_up:16;
  
} fitness_day_record_t; //32Byte
STATIC_ASSERT(sizeof(fitness_day_record_t) == 32);

extern fitness_day_record_t fitness_day_record;

typedef __packed struct
{
  uint8_t tag: 4;      //记录标记
  uint8_t num: 4;
  
  uint32_t duration;//单圈持续时间
  uint32_t distance;//单圈活动距离cm
  
  uint8_t lap_index;
  uint8_t resever[6];
} lap_info_t; //16Byte

typedef __packed struct
{
    uint8_t tag: 4;
    uint8_t num: 4;
  
    uint8_t heartrate; //心率
} hrm_daily_record_t;
STATIC_ASSERT(sizeof(hrm_daily_record_t) == 2);
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum
{
  RECORD_LOGINFO_TAG_TYPE = 0x8000,
  
  RECORD_LOGINFO_TAG_SYSTEM = 0,  //系统日志
  RECORD_LOGINFO_TAG_POWER = 1,   //功耗日志
  RECORD_LOGINFO_TAG_ERROR = 2,   //异常日志
  
  RECORD_LOGINFO_TAG_IDLE = 0xE, 
  RECORD_LOGINFO_TAG_MAGIC = 0xF, 
};

typedef __packed struct
{
    uint8_t tag: 4; 
    uint8_t num:4; 
  
    uint32_t utc;//时间戳
    uint8_t flag;//0->hardfault 1->turnoff 2->reset 3->recovery
    uint32_t LR; 
    uint16_t debug_line;  
    uint8_t reserve[4];
}loginfo_system_t;//16byte

typedef __packed struct
{
    uint8_t tag: 4; 
    uint8_t num:4; 
  
    uint32_t utc_start;//开始时间戳
    uint32_t utc_end;//结束时间戳
    uint16_t cpu_idle_duration; //CPU休眠时间
    uint16_t motor_duration;//马达震动时间s
    uint16_t backlight_duration;//背光时间s
    uint16_t beep_duration;//背光时间s
    uint16_t gps_duration;//GPS持续时间s
    uint16_t hrm_duration;//心率持续次数s
    uint16_t compass_duratuon;//指南针持续时间
    uint32_t ble_uart_times;//蓝牙通信次数
    uint16_t ble_ancs_times;//消息次数
    uint16_t barometer_times;//气压采样次数
    uint8_t reserve[17];
}loginfo_power_t;//48byte
STATIC_ASSERT(sizeof(loginfo_power_t) == 48);

