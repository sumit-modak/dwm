/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 4;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "HackNerdFont:size=16:pixelsize=16:antialias=true:autohint=true" };
static const char dmenufont[]       = "HackNerdFont-Regular:size=12";
static const char nor_bg_col[]      = "#202020";
static const char nor_border_col[]  = "#404040";
static const char nor_fg_col[]      = "#bbbbbb";
static const char sel_bg_col[]      = "#005577";
static const char sel_border_col[]  = "#ddddff";
static const char sel_fg_col[]      = "#eeeeee";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { nor_fg_col, nor_bg_col, nor_border_col },
	[SchemeSel]  = { sel_fg_col, sel_bg_col, sel_border_col },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",     tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", nor_bg_col, "-nf", nor_fg_col, "-sb", sel_bg_col, "-sf", sel_fg_col, NULL };
static const char *termcmd[]  = { "kitty", NULL };

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        				function        argument */
	{ MODKEY,                       XK_o,      				spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, 				spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      				togglebar,      {0} },									// toggles the dwm bar
	{ MODKEY,                       XK_a,      				focusstack,     {.i = +1 } },						// shifts focus in clockwise manner
	{ MODKEY,                       XK_s,      				focusstack,     {.i = -1 } },						// shifts focus in anticlockwise manner
	{ MODKEY,                       XK_bracketleft,   incnmaster,     {.i = +1 } },						// brings adjacent slave window on master stack
	{ MODKEY,                       XK_bracketright,	incnmaster,     {.i = -1 } },						// brings adjacent master window on slave stack
	{ MODKEY,                       XK_k,      				setmfact,       {.f = -0.05} }, 				// resize window - makes master windows smaller
	{ MODKEY,                       XK_v,      				setmfact,       {.f = +0.05} },					// resize window - makes slave windows smaller
	{ MODKEY,                       XK_r,      				movestack,      {.i = +1 } }, 					// move window downwards the stack
	{ MODKEY,                       XK_w,      				movestack,      {.i = -1 } },						// move window upwards the stack
	{ MODKEY,                  			XK_Tab,    				zoom,           {0} },                  // brings window to the master 
	{ MODKEY|ShiftMask,             XK_Tab,    				view,           {0} },									// moves to last used tag
	{ MODKEY,                       XK_q,      				killclient,     {0} },									// kill focused window
	{ MODKEY,                       XK_t,      				setlayout,      {.v = &layouts[0]} },   // sets tiling layout mode
	{ MODKEY,                       XK_f,      				setlayout,      {.v = &layouts[1]} },   // sets floating layout mode
	{ MODKEY,                       XK_m,      				setlayout,      {.v = &layouts[2]} },   // sets monocle layout mode
	{ MODKEY,                       XK_space,  				setlayout,      {0} },									// toggle between last activated mode and current mode for current tag
	{ MODKEY|ShiftMask,             XK_space,  				togglefloating, {0} },									// toggle between last activated mode and current mode for activated window
	TAGKEYS(                        XK_1,             				        0)
	TAGKEYS(                        XK_2,                      				1)
	TAGKEYS(                        XK_3,  				                    2)
	TAGKEYS(                        XK_4,          				            3)
	TAGKEYS(                        XK_5,           				          4)
	TAGKEYS(                        XK_6,                             5)
	TAGKEYS(                        XK_7,                             6)
	TAGKEYS(                        XK_8,                             7)
	TAGKEYS(                        XK_9,                             8)
	{ MODKEY|ShiftMask,             XK_q,             quit,           {0} },									// quits dwm
  { MODKEY,                       XK_minus,  				setgaps,        {.i = -1 } },						// decreases window gaps
	{ MODKEY,                       XK_equal,  				setgaps,        {.i = +1 } },						// increases window gaps
	{ MODKEY|ShiftMask,             XK_equal,  				setgaps,        {.i = 0  } },						// increases window gaps

	// unused shortcuts
	{ MODKEY,                       XK_0,      				view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      				tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_apostrophe, 		focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_colon,      		focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_apostrophe,		tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_colon, 				tagmon,         {.i = +1 } },
	
	// extra added keyboard shortcuts
	{ MODKEY|ShiftMask,             XK_b,             spawn,          SHCMD("~/.local/bin/setbg")}, // sets or changes background
	{ MODKEY,                       XK_comma,         spawn,          SHCMD("maim ~/multimedia/screenshots/\"Screenshot_$(date +%Y-%m-%d_%T).png\"")}, // gets screenhot of full window
	{ MODKEY|ShiftMask,             XK_comma,         spawn,          SHCMD("maim | xclip -selection clipboard -t image/png")}, // gets screenshots of full window and stores in clipboard
  { MODKEY,                       XK_period,        spawn,          SHCMD("maim --select ~/multimedia/screenshots/\"Screenshot_$(date +%Y-%m-%d_%T).png\"")}, // enable user to select screenshot
	{ MODKEY|ShiftMask,             XK_period,        spawn,          SHCMD("maim --select | xclip -selection clipboard -t image/png")}, // enables user to select screenshot and stores in clipboard
	{ MODKEY,						 						XK_l,             spawn, 					SHCMD("slock -m \"Locked at  $(date \"+%a %d, %H:%M:%S\")\"")}
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
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

