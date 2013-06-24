#include "StdAfx.h"
#include "VLCWrapper.h"

CVLCWrapper::CVLCWrapper(void)
{
}

CVLCWrapper::~CVLCWrapper(void)
{

}

bool CVLCWrapper::StartPlayer(const string & url, HWND hwnd, bool forceStart)
{
    if (m_pCurrent && !forceStart)
    {
        assert(0);
        return false;
    }

    m_pCurrent.reset(new PlayTask);
    m_pCurrent->task_vlcInst = libvlc_new(0, NULL);
    if (!m_pCurrent->task_vlcInst)
    {
        assert(0);
        return false;
    }

    m_pCurrent->task_vlcMedia = libvlc_media_new_location(m_pCurrent->task_vlcInst, url.c_str());
    if (!m_pCurrent->task_vlcMedia)
    {
        assert(0);
        return false;
    }
    
    m_pCurrent->task_vlcMplay = libvlc_media_player_new_from_media (m_pCurrent->task_vlcMedia);
    if (!m_pCurrent->task_vlcMplay)
    {
        assert(0);
        return false;
    }

    libvlc_media_release (m_pCurrent->task_vlcMedia);
    m_pCurrent->task_vlcMedia = NULL;
    libvlc_media_player_set_hwnd (m_pCurrent->task_vlcMplay, hwnd);
    libvlc_media_player_play (m_pCurrent->task_vlcMplay);

    return true;
}