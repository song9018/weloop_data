# coding=utf-8

DAILY_STATUS = {
    'STATUS_DATA_L': 0x0000,  # //0xxx xxxx xxxx xxxx  能量值L、步数L
    'STATUS_MODE': 0x8000,  # 10xx xxxx xxxx xxxx    标签模式
    'STATUS_DATE': 0xC000,  # 110x xxxx xxxx xxxx    年月日
    'STATUS_TIME': 0xD800,  # 1101 1xxx xxxx xxxx    时分
    'STATUS_DATA_H': 0xE000,  # 1110 0xxx xxxx xxxx
    'STATUS_SYNC': 0xE800,  # 1110 1xxx xxxx xxxx    SYS_ID
    'STATUS_HR': 0xF000,  # 1111 000x xxxx xxxx     心率
    'STATUS_START': 0xF800,  # 1111 1000 xxxx xxxx  数据头时间戳及时区
    'STATUS_REVERSE': 0xFFFF  # 保留
}


DAILY_MODE = {
    0x0001: "摘下",  # off
    0x0002: "睡眠",  # sleep
    0x0003: "爬楼",  # 爬楼
    0x0010: "散步",  # walk
    0x0020: "健走",  # run  健走
    0x0040: "低运动量",  # low sport
    0x0080: "运动",  # sport
    0x0100: "跑步",  # RUN2  跑步模式
    0x0200: "骑行",  # RIDE  骑行模式
    0x0300: "无氧运动",  # 无氧运动
    0x0400: "游泳",  # SWIM 游泳模式
    0x0700: "reverse"
}
struct_map = {
    'F804': 'sport_ride_summary_t',
    'F814': 'sport_run_summary_t',
    'F824': 'sport_around_t',
    'F80C': 'sport_neo_ride_summary_t',
    'F81C': 'sport_neo_run_summary_t',
    'F82C': 'sport_neo_around_t',
    'F834': 'sport_start_time_t',
    'F844': 'battery_t',
    'F866': 'swim_around_t',
    'F877': 'swim_summary_t',
    'F867': 'swim_around_t',
    'F878': 'swim_summary_t',
    'F88A':'muscle_summary_t'
}
SWIM_STROCK_TYPE={
     0:"混合泳",
     1:"自由泳",
     2:"蛙泳",
     3:"仰泳",
     4:"蝶泳",
     127:"无效"
     }


RECORD_SPORT_TAG = {
    0: "RECORD_TAG_GPS_HEAD",
    1: "RECORD_TAG_GPS_DIFF",
    2: "RECORD_TAG_SPORT_CADENCE_SMALL",
    3: "RECORD_TAG_SPORT_CADENCE",
    4: "RECORD_TAG_SPORT_INFO",
    15: "RECORD_TAG_EXTEND",
    16: "RECORD_TAG_INVALID"
}

RECORD_SPORT_CADENCE_TAG = {
    0: "record_time_t",
    1: "record_peroid_t"
}
RECORD_SPORT_PEROID = {
    0: "peroid_heartrate_t",
    1: "peroid_step_t",
    2: "peroid_step_len_t",
    3: "peroid_step_speed_t",  # 踏频
    4: "peroid_trust_level_t"
}
SPORT_SIZE = {
    "RECORD_TAG_GPS_HEAD": 16,
    "RECORD_TAG_GPS_DIFF": 8,
    "RECORD_TAG_SPORT_CADENCE": 16,
    "RECORD_TAG_EXTEND": 16,
    "RECORD_TAG_INVALID": 16
}

INCH = ['公制', '英制']