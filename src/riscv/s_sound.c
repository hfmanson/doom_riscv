/*
 * s_sound.c
 *
 * Dummy sound code
 *
 * Copyright (C) 2021 Sylvain Munaut
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <unistd.h>
#include "config.h"
#include "console.h"
#include "s_sound.h"

struct wb_esplnk {
	uint32_t csr;
	uint32_t fid;
	uint32_t ofs;
	uint32_t len;
	uint32_t dat;
	uint32_t snd;
} __attribute__((packed,aligned(4)));

static volatile struct wb_esplnk * const esplnk_regs = (void*)(ESPLNK_BASE);

/* Sound */
/* ----- */

void
S_Init
( int sfxVolume,
  int musicVolume )
{
}

void S_Start(void)
{
}

void
S_StartSound
( void* origin,
  int   sound_id )
{
	console_printf("S_StartSound, sound_id = %d\n", sound_id);
	while ((esplnk_regs->csr & (1 << 30)));
	esplnk_regs->snd = sound_id;
}

void
S_StartSoundAtVolume
( void* origin,
  int   sound_id,
  int   volume )
{
	console_printf("S_StartSoundAtVolume, sound_id = %d, volume = %d\n", sound_id, volume);
	while ((esplnk_regs->csr & (1 << 30)));
	esplnk_regs->snd = sound_id;
}

void
S_StopSound(void* origin)
{
}


void
S_PauseSound(void)
{
}

void
S_ResumeSound(void)
{
}


void
S_UpdateSounds(void* listener)
{
}


/* Music */
/* ----- */

void
S_StartMusic(int music_id)
{
}

void
S_ChangeMusic
( int music_id,
  int looping )
{
}

void
S_StopMusic(void)
{
}


/* Volumes */
/* ------- */

	/* Must exist for settings loading code ... */
int snd_SfxVolume;
int snd_MusicVolume;
int numChannels;

void
S_SetMusicVolume(int volume)
{
}

void
S_SetSfxVolume(int volume)
{
}
