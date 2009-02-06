/* libmpdclient
   (c) 2003-2008 The Music Player Daemon Project
   This project's homepage is: http://www.musicpd.org

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   - Neither the name of the Music Player Daemon nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MPD_STATUS_H
#define MPD_STATUS_H

#include <mpd/connection.h>

/* use these with status.state to determine what state the player is in */
#define MPD_STATUS_STATE_UNKNOWN	0
#define MPD_STATUS_STATE_STOP		1
#define MPD_STATUS_STATE_PLAY		2
#define MPD_STATUS_STATE_PAUSE		3

/* us this with status.volume to determine if mpd has volume support */
#define MPD_STATUS_NO_VOLUME		-1

/* struct mpd_status
 * holds info about MPD status
 */
struct mpd_status;

#ifdef __cplusplus
extern "C" {
#endif

void mpd_send_status(struct mpd_connection * connection);

/* mpd_get_status
 * returns status info, be sure to free it with mpd_free_status()
 * call this after mpd_send_status()
 */
struct mpd_status * mpd_get_status(struct mpd_connection * connection);

/* mpd_free_status
 * free's status info malloc'd and returned by mpd_get_status
 */
void mpd_free_status(struct mpd_status * status);

/**
 * Returns the current volume: 0-100, or MPD_STATUS_NO_VOLUME when there is no
 * volume support
 */
int mpd_status_get_volume(struct mpd_status * status);

/**
 * Returns 1 if repeat is on, 0 otherwise
 */
int mpd_status_get_repeat(struct mpd_status * status);

/**
 * Returns 1 if random is on, 0 otherwise
 */
int mpd_status_get_random(struct mpd_status * status);

/**
 * Returns playlist length
 */
int mpd_status_get_playlist_length(struct mpd_status * status);

/**
 * Returns playlist number, use this to determine when the playlist has changed
 */
long long mpd_status_get_playlist(struct mpd_status * status);

/**
 * Returns the state of the player (use with MPD_STATUS_STATE_*)
 */
int mpd_status_get_state(struct mpd_status * status);

/**
 * Returns crossfade setting in seconds
 */
int mpd_status_get_crossfade(struct mpd_status * status);

/**
 * Returns the position of the currently playing song in the playlist
 * (beginning with 0) if a song is currently selected (always the case when
 * state is PLAY or PAUSE)
 */
int mpd_status_get_song(struct mpd_status * status);

/**
 * Returns Song ID of the currently selected song
 */
int mpd_status_get_songid(struct mpd_status * status);

/**
 * Returns time in seconds that have elapsed in the currently playing/paused
 * song
 */
int mpd_status_get_elapsed_time(struct mpd_status * status);

/**
 * Returns the length in seconds of the currently playing/paused song
 */
int mpd_status_get_total_time(struct mpd_status * status);

/**
 * Returns current bit rate in kbs
 */
int mpd_status_get_bit_rate(struct mpd_status * status);

/**
 * Returns audio sample rate
 */
unsigned int mpd_status_get_sample_rate(struct mpd_status * status);

/**
 * Returns audio bits
 */
int mpd_status_get_bits(struct mpd_status * status);

/**
 * Returns audio channels
 */
int mpd_status_get_channels(struct mpd_status * status);

/**
 * Returns 1 if mpd is updating, 0 otherwise
 */
int mpd_status_get_updatingdb(struct mpd_status * status);

/**
 * Returns the error message
 */
char * mpd_status_get_error(struct mpd_status * status);

#ifdef __cplusplus
}
#endif

#endif
