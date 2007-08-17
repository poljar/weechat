/*
 * Copyright (c) 2003-2007 by FlashCode <flashcode@flashtux.org>
 * See README for License detail, AUTHORS for developers list.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef __WEECHAT_CONFIG_H
#define __WEECHAT_CONFIG_H 1

#include "../irc/irc.h"

#define WEECHAT_CONFIG_NAME "weechat.rc"

#define CONFIG_SECTION_NONE    -1
#define CONFIG_SECTION_LOOK    0
#define CONFIG_SECTION_COLORS  1
#define CONFIG_SECTION_HISTORY 2
#define CONFIG_SECTION_LOG     3
#define CONFIG_SECTION_IRC     4
#define CONFIG_SECTION_DCC     5
#define CONFIG_SECTION_PROXY   6
#define CONFIG_SECTION_PLUGINS 7
#define CONFIG_SECTION_KEYS    8
#define CONFIG_SECTION_ALIAS   9
#define CONFIG_SECTION_IGNORE  10
#define CONFIG_SECTION_SERVER  11
#define CONFIG_NUMBER_SECTIONS 12

#define OPTION_TYPE_BOOLEAN         1   /* values: on/off                   */
#define OPTION_TYPE_INT             2   /* values: from min to max          */
#define OPTION_TYPE_INT_WITH_STRING 3   /* values: one from **array_values  */
#define OPTION_TYPE_COLOR           4   /* values: a color name             */
#define OPTION_TYPE_STRING          5   /* values: any string, may be empty */

#define BOOL_FALSE 0
#define BOOL_TRUE  1

#define CFG_LOOK_NICKLIST_LEFT   0
#define CFG_LOOK_NICKLIST_RIGHT  1
#define CFG_LOOK_NICKLIST_TOP    2
#define CFG_LOOK_NICKLIST_BOTTOM 3

#define CFG_LOOK_ALIGN_NICK_NONE  0
#define CFG_LOOK_ALIGN_NICK_LEFT  1
#define CFG_LOOK_ALIGN_NICK_RIGHT 2

#define CFG_LOOK_HOTLIST_SORT_GROUP_TIME_ASC    0
#define CFG_LOOK_HOTLIST_SORT_GROUP_TIME_DESC   1
#define CFG_LOOK_HOTLIST_SORT_GROUP_NUMBER_ASC  2
#define CFG_LOOK_HOTLIST_SORT_GROUP_NUMBER_DESC 3
#define CFG_LOOK_HOTLIST_SORT_NUMBER_ASC        4
#define CFG_LOOK_HOTLIST_SORT_NUMBER_DESC       5

#define CFG_IRC_DISPLAY_AWAY_OFF     0
#define CFG_IRC_DISPLAY_AWAY_LOCAL   1
#define CFG_IRC_DISPLAY_AWAY_CHANNEL 2

typedef struct t_config_section t_config_section;

struct t_config_section
{
    int section_number;
    char *section_name;
};

typedef struct t_config_option t_config_option;

struct t_config_option
{
    char *option_name;
    char *short_description;
    char *long_description;
    int option_type;
    int min, max;
    int default_int;
    char *default_string;
    char **array_values;
    int *ptr_int;
    char **ptr_string;
    void (*handler_change)();
};

extern int cfg_look_save_on_exit;
extern int cfg_look_set_title;
extern int cfg_look_startup_logo;
extern int cfg_look_startup_version;
extern char *cfg_look_weechat_slogan;
extern int cfg_look_one_server_buffer;
extern int cfg_look_open_near_server;
extern int cfg_look_scroll_amount;
extern char *cfg_look_buffer_timestamp;
extern int cfg_look_color_nicks_number;
extern int cfg_look_color_actions;
extern int cfg_look_nicklist;
extern int cfg_look_nicklist_position;
extern int cfg_look_nicklist_min_size;
extern int cfg_look_nicklist_max_size;
extern int cfg_look_nicklist_separator;
extern int cfg_look_nickmode;
extern int cfg_look_nickmode_empty;
extern char *cfg_look_no_nickname;
extern char *cfg_look_nick_prefix;
extern char *cfg_look_nick_suffix;
extern int cfg_look_align_nick;
extern int cfg_look_align_other;
extern int cfg_look_align_size;
extern int cfg_look_align_size_max;
extern char *cfg_look_nick_completor;
extern char *cfg_look_nick_completion_ignore;
extern int cfg_look_nick_completion_smart;
extern int cfg_look_nick_complete_first;
extern int cfg_look_infobar;
extern char *cfg_look_infobar_timestamp;
extern int cfg_look_infobar_seconds;
extern int cfg_look_infobar_delay_highlight;
extern int cfg_look_hotlist_names_count;
extern int cfg_look_hotlist_names_level;
extern int cfg_look_hotlist_names_length;
extern int cfg_look_hotlist_sort;
extern int cfg_look_day_change;
extern char *cfg_look_day_change_timestamp;
extern char *cfg_look_read_marker;
extern char *cfg_look_input_format;
extern int cfg_look_paste_max_lines;

extern int cfg_col_real_white;
extern int cfg_col_separator;
extern int cfg_col_title;
extern int cfg_col_title_more;
extern int cfg_col_title_bg;
extern int cfg_col_chat;
extern int cfg_col_chat_time;
extern int cfg_col_chat_time_sep;
extern int cfg_col_chat_prefix1;
extern int cfg_col_chat_prefix2;
extern int cfg_col_chat_server;
extern int cfg_col_chat_join;
extern int cfg_col_chat_part;
extern int cfg_col_chat_nick;
extern int cfg_col_chat_host;
extern int cfg_col_chat_channel;
extern int cfg_col_chat_dark;
extern int cfg_col_chat_highlight;
extern int cfg_col_chat_bg;
extern int cfg_col_chat_read_marker;
extern int cfg_col_chat_read_marker_bg;
extern int cfg_col_status;
extern int cfg_col_status_delimiters;
extern int cfg_col_status_channel;
extern int cfg_col_status_data_msg;
extern int cfg_col_status_data_private;
extern int cfg_col_status_data_highlight;
extern int cfg_col_status_data_other;
extern int cfg_col_status_more;
extern int cfg_col_status_bg;
extern int cfg_col_infobar;
extern int cfg_col_infobar_delimiters;
extern int cfg_col_infobar_highlight;
extern int cfg_col_infobar_bg;
extern int cfg_col_input;
extern int cfg_col_input_server;
extern int cfg_col_input_channel;
extern int cfg_col_input_nick;
extern int cfg_col_input_delimiters;
extern int cfg_col_input_text_not_found;
extern int cfg_col_input_actions;
extern int cfg_col_input_bg;
extern int cfg_col_nick;
extern int cfg_col_nick_away;
extern int cfg_col_nick_chanowner;
extern int cfg_col_nick_chanadmin;
extern int cfg_col_nick_op;
extern int cfg_col_nick_halfop;
extern int cfg_col_nick_voice;
extern int cfg_col_nick_user;
extern int cfg_col_nick_more;
extern int cfg_col_nick_sep;
extern int cfg_col_nick_self;
extern int cfg_col_nick_colors[GUI_COLOR_WIN_NICK_NUMBER];
extern int cfg_col_nick_private;
extern int cfg_col_nick_bg;
extern int cfg_col_dcc_selected;
extern int cfg_col_dcc_waiting;
extern int cfg_col_dcc_connecting;
extern int cfg_col_dcc_active;
extern int cfg_col_dcc_done;
extern int cfg_col_dcc_failed;
extern int cfg_col_dcc_aborted;

extern int cfg_history_max_lines;
extern int cfg_history_max_commands;
extern int cfg_history_display_default;

extern int cfg_log_auto_server;
extern int cfg_log_auto_channel;
extern int cfg_log_auto_private;
extern int cfg_log_plugin_msg;
extern char *cfg_log_path;
extern char *cfg_log_timestamp;
extern int cfg_log_hide_nickserv_pwd;

extern int cfg_irc_display_away;
extern int cfg_irc_show_away_once;
extern char *cfg_irc_default_msg_part;
extern char *cfg_irc_default_msg_quit;
extern int cfg_irc_notice_as_pv;
extern int cfg_irc_away_check;
extern int cfg_irc_away_check_max_nicks;
extern int cfg_irc_lag_check;
extern int cfg_irc_lag_min_show;
extern int cfg_irc_lag_disconnect;
extern int cfg_irc_anti_flood;
extern int cfg_irc_fifo_pipe;
extern char *cfg_irc_highlight;
extern int cfg_irc_colors_receive;
extern int cfg_irc_colors_send;
extern int cfg_irc_send_unknown_commands;

extern int cfg_dcc_auto_accept_files;
extern int cfg_dcc_auto_accept_chats;
extern int cfg_dcc_timeout;
extern int cfg_dcc_blocksize;
extern int cfg_dcc_fast_send;
extern char *cfg_dcc_port_range;
extern char *cfg_dcc_own_ip;
extern char *cfg_dcc_download_path;
extern char *cfg_dcc_upload_path;
extern int cfg_dcc_convert_spaces;
extern int cfg_dcc_auto_rename;
extern int cfg_dcc_auto_resume;

extern int cfg_proxy_use;
extern int cfg_proxy_type;
extern char *cfg_proxy_type_values[];
extern int cfg_proxy_ipv6;
extern char *cfg_proxy_address;
extern int cfg_proxy_port;
extern char *cfg_proxy_username;
extern char *cfg_proxy_password;

extern char *cfg_plugins_path;
extern char *cfg_plugins_autoload;
extern char *cfg_plugins_extension;

extern t_config_section config_sections [CONFIG_NUMBER_SECTIONS];
extern t_config_option * weechat_options [CONFIG_NUMBER_SECTIONS];

extern char *config_get_section ();
extern void config_change_noop ();
extern void config_change_save_on_exit ();
extern void config_change_title ();
extern void config_change_buffers ();
extern void config_change_buffer_content ();
extern void config_change_hotlist ();
extern void config_change_read_marker ();
extern void config_change_charset ();
extern void config_change_one_server_buffer ();
extern void config_change_color ();
extern void config_change_nicks_colors ();
extern void config_change_away_check ();
extern void config_change_fifo_pipe ();
extern void config_change_notify_levels ();
extern void config_change_log ();
extern int config_option_set_value (t_config_option *, char *);
extern void config_option_list_remove (char **, char *);
extern void config_option_list_set (char **, char *, char *);
extern void config_option_list_get_value (char **, char *, char **, int *);
extern t_config_option *config_option_search (char *);
extern void config_option_search_option_value (char *, t_config_option **, void **);
extern int config_set_value (char *, char *);
extern void *config_get_server_option_ptr (t_irc_server *, char *);
extern int config_set_server_value (t_irc_server *, char *, char *);
extern int config_read ();
extern int config_create_default ();
extern int config_write ();

#endif /* weeconfig.h */
