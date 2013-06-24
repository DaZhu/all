#ifndef __VLCWRAPPER__H__
#define __VLCWRAPPER__H__
#include <vlc/vlc.h>
#include <boost/shared_ptr.hpp>
#pragma comment(lib, "libvlc.lib")
#pragma comment(lib, "libvlccore.lib")

class CVLCWrapper
{
    struct PlayTask
    {
        PlayTask()
        {
            task_vlcInst = NULL;
            task_vlcMplay = NULL;
            task_vlcMedia = NULL;
        }
        ~PlayTask()
        {
            if (task_vlcMplay)
            {
                libvlc_media_player_release(task_vlcMplay);
                task_vlcMplay = NULL;
            }

            if (task_vlcMedia)
            {
                libvlc_media_release(task_vlcMedia);
                task_vlcMedia = NULL;
            }

            if (task_vlcInst)
            {
                libvlc_release (task_vlcInst);
                task_vlcInst = NULL;
            }
        }

        libvlc_instance_t*      task_vlcInst;  
        libvlc_media_player_t*  task_vlcMplay;  
        libvlc_media_t*         task_vlcMedia;  
    };

private:
    CVLCWrapper(void);
public:
    ~CVLCWrapper(void);

    static CVLCWrapper & GetInstance() 
    {
        static CVLCWrapper s_wrapper;
        return s_wrapper;
    }

    bool StartPlayer(const string & url, HWND hwnd, bool forceStart);
    

    
private:
    boost::shared_ptr<PlayTask> m_pCurrent;
};



#endif //__VLCWRAPPER__H__