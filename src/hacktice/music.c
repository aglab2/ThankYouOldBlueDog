#include "music.h"
#include "binary.h"
#include "cfg.h"

#include "audio/load.h"

void Music_setVolumeHook(struct SequenceChannel *seqChannel, u8 volume)
{
    if (Config_muteMusic())
        volume = 0;

    seqChannel->volume = FLOAT_CAST(volume) / 127.0f;
}

void Music_onFrame()
{    
    int music = Config_musicNumber();
    if (!music)
        return;

    if (tSequencePlayers[0].seqId != music)
        PLAY_SEQUENCE(0, music, 0);
}

void probeStore(void* addr, u32 val)
{
    *(vu32*) addr = val;
}

u32 probeLoad(void* addr)
{
    return *(vu32*) addr;
}