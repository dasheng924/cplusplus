#include <iostream>

using namespace std;

class Remote ;

class Tv
{
    /*
    friend void Remote::setChannel(int channel);
    friend void Remote::setVol(int vol);
    */
   friend class Remote ;

public:
    enum{On,Off};//电视状态
    enum{minVol,maxVol=100};//电视音量0-100
    enum{minChannel,maxChannel=255};//电视频道 0-255
    


    Tv()
    {
        m_status =Off;
        m_volume = minVol;
        m_channel = minChannel;
    }

    Tv(int num)
    {
        m_status = getStatus();
        m_channel = getChannel();
        m_volume = getVol();
    }
    
    int getStatus(){return m_status ;}
    int getVol(){return m_volume;}
    int getChannel(){return m_channel ;}
    //open Tv
    void OnOrOff()
    {
        this ->m_status = (this->m_status == On ?Off:On) ;
    }
    //调高音量
    void UpVol()
    {
        if(this->m_volume >= maxVol)
            return;
        this->m_volume ++;
    }
    //调低音量
    void DownVol()
    {
        if(this->maxVol <= minVol)
            return ;
        this->m_volume--;
    }

    //增加频道
    void UpChannel()
    {
        if(this->m_channel >=maxChannel)
            return;
        this->m_channel++;
    }

    //减下频道
    void DownChannel()
    {
        if(this->m_channel <= minChannel)
            return;
        this->m_channel--;
    }

    //展示当前电视机状态
    void showStatus()
    {
        cout<<"开机状态:"<<(m_status == On ? "已打开":"已关闭")<<endl; 
        if(m_status == On)
        {
            cout<<"电视机的频道是,频道"<<m_channel<<"号"<<endl ;
            cout<<"电视机的音量是,音量"<<m_volume<<endl ;
        }
    }



private:
    int m_status;
    int m_volume;
    int m_channel;
};

class Remote
{
public:
    Remote(Tv * p)
    {
        m_pTv = p; 
    }

    //开机
    void OnOrOff()
    {
        m_pTv->OnOrOff();
    }
    //调高音量
    void UpVol()
    {
        m_pTv->UpVol();
    }
    void DownVol()
    {
        m_pTv->DownVol();
    }
    //调高频道
    void UpChannel()
    {
        m_pTv->UpChannel();
    }

    void Down()
    {
        m_pTv->DownChannel();
    }

    //设置频道  
    void setChannel(int channel)
    {
        if(channel < Tv::minChannel || channel > Tv::maxChannel )
            return ;
        m_pTv->m_channel  = channel;
    }

    //设置音量      
    void setVol(int vol)
    {
        if(vol < Tv::minVol || vol > Tv::maxVol)
            return ;
        m_pTv->m_volume = vol ;
    }

    //显示电视状态信息
    void showStatus()
    {
        m_pTv->showStatus();
    }

private:
    Tv * m_pTv ;
};


void test01()
{
    Tv t1;
    t1.showStatus() ;
    t1.OnOrOff(); // 打开电视机
    t1.showStatus();
    t1.UpChannel();
    t1.UpVol();
    t1.showStatus();
}

void test02()
{
   Remote r1(new Tv) ;
   r1.OnOrOff();
   r1.setChannel(10);
   r1.setVol(45) ;
   r1.showStatus() ;

}


int main(void)
{
    //test01();
    
    test02() ;

    return 0 ;
}