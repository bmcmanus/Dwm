/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "Inconsolata 10";
static const char normbordercolor[] = "#0066ff";
static const char normbgcolor[]     = "#303030";
static const char normfgcolor[]     = "#909090";
static const char selbordercolor[]  = "#f11010";
static const char selbgcolor[]      = "#909090";
static const char selfgcolor[]      = "#303030";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

#define BOTTOM_BAR_HEIGHT 0
/* tagging */
static const char *tags[] = { "t", "n", "c", "m", "g", "v", "o" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,        1 << 4,            True,        -1 },
	{ "Inkscape",     NULL,       NULL,        1 << 4,            False,        -1 },
	{ "Gnome-mplayer",     NULL,       NULL,        1 << 3,            True,        -1 },
	{ "Mplayer",     NULL,       NULL,        1 << 3,            True,        -1 },
	{ "Shiretoko",  NULL,       NULL,       1 << 1,       False,       -1 },
	{ "OpenOffice",  NULL,       NULL,       1 << 6,       False,       -1 },
	{ NULL,  NULL,       "Terminal",       1 << 0,       False,       -1 },
	{ NULL,  NULL,       "mutt",       1 << 2,       False,       -1 },
	{ NULL,  NULL,       "ncmpcpp",       1 << 3,       False,       -1 },
	{ NULL,  NULL,       "irssi",       1 << 2,       False,       -1 },
	{ "Wfica_Seamless",  NULL,       NULL,       1 << 2,       True,       -1 },
	{ "VirtualBox",  NULL,       NULL,       1 << 5,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.50; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = False; /* False means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "*B*",      bstack },         /* first entry is default */
	{ "*T*",      tile },    	
	{ "*F*",      NULL },    /* no layout function means floating behavior */
	{ "*M*",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu-launch.sh", };
static const char *termcmd[]  = { "urxvtc", NULL };
static const char *termshcmd[]  = { "urxvtc", "-e", "screen", "-d", "-R", "-t", "urxvt", "-S", "terminal", NULL };
static const char *irssi[]  = { "urxvtc", "-title", "irssi", "-e", "screen", "-d", "-R", "-t", "irssi", "-S", "irssi", "irssi", NULL };
static const char *wificmd[]  = {  "urxvtc", "-title", "wifi-select", "-e", "sudo","wifi-select", "wlan0", NULL };
static const char *webcmd[]  = { "firefox", NULL };
static const char *filemgr[]  = { "pcmanfm", NULL };
static const char *mailcmd[]  = { "urxvtc", "-title", "mutt", "-e","mutt", NULL };
static const char *musiccmd[]  = { "urxvtc", "-title", "ncmpcpp", "-e","ncmpcpp", NULL };
static const char *lockcmd[]  = { "lockx", NULL };
static const char *volume_up[]  = { "amixer", "set", "Master", "2%+", NULL };
static const char *volume_down[]  = { "amixer", "set", "Master", "2%-", NULL };
static const char *volume_mute[]  = { "amixer", "set", "Master", "toggle", NULL };
static const char *mpd_play[]  = { "mpc", "toggle", NULL };
static const char *mpd_next[]  = { "mpc", "next", NULL };
static const char *mpd_prev[]  = { "mpc", "prev", NULL };
static const char *mpd_stop[]  = { "mpc", "stop", NULL };
static const char *htop[]  = { "urxvtc", "-title", "htop", "-e", "htop", NULL };
static const char *notes[]  = { "urxvtc", "-title", "Notes", "-e", "vim", "/home/firecat53/docs/notes.txt", NULL };
static const char *caltodo[]  = { "firefox", "calendar.google.com", NULL };
static const char *snipload[]  = { "snip", "load", NULL };
static const char *snipsave[]  = { "snip", "save", NULL };
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = htop } },
	{ ALTKEY,                       XK_Return, spawn,          {.v = dmenucmd } },
	{ MODKEY,             		XK_z, 	   spawn,          {.v = termcmd } },
	{ MODKEY,             		XK_x, 	   spawn,          {.v = filemgr } },
	{ MODKEY|ShiftMask,    		XK_z, 	   spawn,          {.v = termshcmd } },
	{ MODKEY,             		XK_w, 	   spawn,          {.v = webcmd } },
	{ MODKEY,             		XK_r, 	   spawn,          {.v = irssi } },
	{ MODKEY,             		XK_e, 	   spawn,          {.v = mailcmd } },
	{ MODKEY,             		XK_a, 	   spawn,          {.v = notes } },
	{ MODKEY,             		XK_i, 	   spawn,          {.v = wificmd } },
	{ MODKEY,             		XK_g, 	   spawn,          {.v = caltodo } },
	{ MODKEY,             		XK_n, 	   spawn,          {.v = musiccmd } },
	{ MODKEY,             		XK_q, 	   spawn,          {.v = snipload } },
	{ MODKEY|ALTKEY,    		XK_q, 	   spawn,          {.v = snipsave } },
	{ MODKEY|ALTKEY,      		XK_l, 	   spawn,          {.v = lockcmd } },
	{ ALTKEY|ControlMask,  		XK_l, 	   spawn,          {.v = lockcmd } },
	{ 0,  		 		 0x1008ff13, 	   spawn,          {.v = volume_up } },
	{ 0,  		 		 0x1008ff11, 	   spawn,          {.v = volume_down } },
	{ 0,  		 		 0x1008ff12, 	   spawn,          {.v = volume_mute } },
	{ 0,  		 		 0x1008ff14, 	   spawn,          {.v = mpd_play} },
	{ 0,  		 		 0x1008ff17, 	   spawn,          {.v = mpd_next} },
	{ 0,  		 		 0x1008ff16, 	   spawn,          {.v = mpd_prev} },
	{ 0,  		 		 0x1008ff15, 	   spawn,          {.v = mpd_stop} },
	{ MODKEY,                       XK_s,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_Left,   view_prev_tag,  {0} },
	{ MODKEY,                       XK_Right,  view_next_tag,  {0} },
	{ ALTKEY|ControlMask,           XK_Left,   view_prev_tag,  {0} },
	{ ALTKEY|ControlMask,           XK_Right,  view_next_tag,  {0} },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be a tag number (starting at 0),
 * ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

