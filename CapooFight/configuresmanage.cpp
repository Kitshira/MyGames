#include "configuresmanage.h"

int Datas::GoldRemain=0;
int Datas::TOTALDEFBuff=0;
int Datas::TOTALSPEBuff=0;

int Datas::TYPE=0;
double Datas::C_X=790;
double Datas::C_Y=540;
int Datas::ATKBuff=0;
int Datas::DEFBuff=0;
int Datas::SPEBuff=0;
int Datas::HP=100;
int Datas::LEVEL=1;
int Datas::EXP=0;

Datas::Datas(int a){
    totalsetting = new QSettings("./TOTALDATA.ini",QSettings::IniFormat);
    switch(a){
       case -1:
        settings = new QSettings("./Save-1.ini",QSettings::IniFormat);
       case 0:
        settings = new QSettings("./Save0.ini",QSettings::IniFormat);
        break;
       case 1:
        settings = new QSettings("./Save1.ini",QSettings::IniFormat);
        break;
       case 2:
        settings = new QSettings("./Save2.ini",QSettings::IniFormat);
        break;
       case 3:
        settings = new QSettings("./Save3.ini",QSettings::IniFormat);
        break;
       default:
        settings = new QSettings("./Save0.ini",QSettings::IniFormat);
    }
}

void Datas::readConfig(){
    Datas::GoldRemain=totalsetting->value("GoldRemain",0).toInt();
    Datas::TOTALDEFBuff=totalsetting->value("TOTALDEFBuff",0).toInt();
    Datas::TOTALSPEBuff=totalsetting->value("TOTALSPEBuff",0).toInt();

    Datas::TYPE=settings->value("TYPE",0).toInt();
    Datas::C_X=settings->value("C_X",790).toDouble();
    Datas::C_Y=settings->value("C_Y",540).toDouble();
    Datas::ATKBuff=settings->value("ATKBuff",0).toInt();
    Datas::DEFBuff=settings->value("DEFBuff",0).toInt();
    Datas::SPEBuff=settings->value("SPEBuff",0).toInt();
    Datas::HP=settings->value("HPRemain",0).toInt();
    Datas::LEVEL=settings->value("LEVEL",0).toInt();
    Datas::EXP=settings->value("EXP",0).toInt();
}
void Datas::clearConfig(){
    Datas::TYPE=settings->value("TYPE",0).toInt();
    Datas::C_X=740;
    Datas::C_Y=580;
    Datas::ATKBuff=0;
    Datas::DEFBuff=0;
    Datas::SPEBuff=0;
    Datas::HP=100;
    Datas::LEVEL=1;
    Datas::EXP=0;
}
void Datas::writeConfig(){
    totalsetting->setValue("GoldRemain",Datas::GoldRemain);
    totalsetting->setValue("TOTALDEFBuff",Datas::TOTALDEFBuff);
    totalsetting->setValue("TOTALSPEBuff",Datas::TOTALSPEBuff);

    settings->setValue("TYPE",Datas::TYPE);
    settings->setValue("C_X",Datas::C_X);
    settings->setValue("C_Y",Datas::C_Y);
    settings->setValue("ATKBuff",Datas::ATKBuff);
    settings->setValue("DEFBuff",Datas::DEFBuff);
    settings->setValue("SPEBuff",Datas::SPEBuff);
    settings->setValue("HPRemain",Datas::HP);
    settings->setValue("LEVEL",Datas::LEVEL);
    settings->setValue("EXP",Datas::EXP);
}

int Datas::getGameValue(const QString &key){
    if(key=="GoldRemain"||key=="TOTALDEFBuff"||key=="TOTALSPEBuff"){
        return totalsetting->value(key,0).toInt();
    }
        return settings->value(key,0).toInt();
}

void Datas::setGameValue(const QString &key, int value){
    if(key=="GoldRemain"){
        Datas::GoldRemain=value;
        totalsetting->setValue(key,value);
    }
    else if(key=="TOTALDEFBuff"){
        Datas::TOTALDEFBuff=value;
        totalsetting->setValue(key,value);
    }
    else if(key=="TOTALSPEBuff"){
        Datas::TOTALSPEBuff=value;
        totalsetting->setValue(key,value);
    }
    else if(key=="TYPE"){
        Datas::TYPE=value;
        totalsetting->setValue(key,value);
    }
    else if(key=="C_X"){
        Datas::C_X=value;
        totalsetting->setValue(key,value);
    }
    else if(key=="C_Y"){
        Datas::C_Y=value;
        totalsetting->setValue(key,value);
    }
    else if(key=="ATKBuff"){
        Datas::ATKBuff=value;
        settings->setValue(key,value);
    }
    else if(key=="DEFBuff"){
        Datas::DEFBuff=value;
        settings->setValue(key,value);
    }
    else if(key=="SPEBuff"){
        Datas::SPEBuff=value;
        settings->setValue(key,value);
    }
    else if(key=="HPRemain"){
        Datas::HP=value;
        settings->setValue(key,value);
    }
    else if(key=="LEVEL"){
        Datas::LEVEL=value;
        settings->setValue(key,value);
    }
    else if(key=="EXP"){
        Datas::EXP=value;
        settings->setValue(key,value);
    }
}
