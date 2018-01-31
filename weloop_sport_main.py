# coding=utf-8
import weloop_struct, glob
from weloop_function_struct import *
from weloop_create_kml import *


def read_daily(data,path):
    daily_file = open("./result/%s_daily_data.txt" % path, "w", encoding="utf-8")
    DAILY = weloop_struct.daily_struct(daily_file)
    DAILY.decode_daily(data)
    daily_file.close()


def read_sport(data, path):
    gps_file = open("./result/%s_gps_data.txt" % path, "w", encoding="utf-8")
    sport_file = open("./result/%s_sport_data.txt" % path, "w", encoding="utf-8")
    read_sport_data(data, gps_file, sport_file)
    gps_file.close()
    sport_file.close()

def read_sport_data(pstr, gps_file, sport_file):
    i = 0
    size = 1
    SPORT = weloop_struct.sport_struct(gps_file, sport_file)
    while i < len(pstr):

        tag = (eval("0x" + pstr[i:i + size * 2][0:2])) & 0x0f

        size =SPORT_SIZE[RECORD_SPORT_TAG[tag]]
        ppstr = pstr[i:i + size * 2]
        i += size * 2
        getattr(SPORT, RECORD_SPORT_TAG[tag])(ppstr)


def run_sport_info():
    file = glob.glob("*.txt")
    for i in range(len(file)):
        filename = file[i]
        with  open(filename, "r", encoding="utf-8") as fp:
            data = fp.readlines()
        if data != []:
            path_name = filename.split(".txt")[0]
            data = data[0].replace(" ", "")
            if str(data[0:4]).upper()=="01E8":
                read_daily(data,path_name)
            # else:
            #     read_sport(data, path_name)
        #gps_file_fenduan("./result/%s_gps_data.txt" % path_name)


def create_kml_file():
    try:
        file1 = glob.glob("./result/*_gps_data*.txt")
        for i in range(len(file1)):
            path_name = file1[i].split("result\\")[1].split(".txt")
            get_pdr_kml(file1[i], "./result/%s.kml" % path_name[0])
    except Exception as e:
        
        print(e)

def remove():
    file0 = glob.glob("./result/*")
    for i in range(len(file0)):
        os.remove(file0[i])


if __name__ == '__main__':
    remove()
    run_sport_info()
    create_kml_file()
    print("解析完成！！！")
