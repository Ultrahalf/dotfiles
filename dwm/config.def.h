/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 1;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 0;   /* 0 means derive from font, >= 1 explicit height */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_NONE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static int fakefsindicatortype           = INDICATOR_PLUS;
static int floatfakefsindicatortype      = INDICATOR_PLUS_AND_LARGER_SQUARE;
static const char *fonts[]          	 = { "Source Code Pro:size=10", "JoyPixels:pixelsize=10:antialias=true:autohint=true"  };
static const char dmenufont[]            = "Source Code Pro:size=10";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";



static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",      spcmd2},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
	[ALT_TAGS_DECORATION] = { "1", "2", "3", "::", "::-", ":::", ":::-", ":::::", "::::-" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
	RULE(.instance = "spcalc", .tags = SPTAG(1), .isfloating = 1)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor  bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{ -1,       0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
	{  0,       0,     BAR_ALIGN_RIGHT,  width_systray,           draw_systray,           click_systray,           "systray" },
	{ -1,       0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{ 'A',      0,     BAR_ALIGN_RIGHT,  width_status2d,          draw_status2d,          click_statuscmd,         "status2d" },
	{ -1,       0,     BAR_ALIGN_NONE,   width_wintitle,          draw_wintitle,          click_wintitle,          "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
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
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	topbar ? NULL : "-b",
	NULL
};
static const char *termcmd[]  = { "st", NULL };

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"
#include <X11/XF86keysym.h>


static Key keys[] = {
	/* modifier                     key            function                argument */
    /* change the key based on your layout */
	{ MODKEY,                       XK_d,          spawn,                  {.v = dmenucmd } },
	{ MODKEY|ShiftMask,				XK_d,		   spawn,				   SHCMD("passmenu") },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_i,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_u,          focusurgent,            {0} },
	{ MODKEY,						XK_e,			spawn,					SHCMD("st -e ranger") },
	{ MODKEY,						XK_r,			spawn,					SHCMD("st -e ranger") },
	{ MODKEY|ShiftMask,				XK_h,			spawn,					SHCMD("st -e htop") },
	{ MODKEY,                       XK_n,           togglealttag,           {0} },
	/* Audio */
	{ MODKEY,						XK_p,			spawn,					SHCMD("mpc toggle ; pauseallmpv") },
	{ MODKEY,						XK_m,			spawn,					SHCMD("st -e ncmpcpp") },
	/* Movement */
	{ MODKEY,              			XK_semicolon,	shiftviewclients,       { .i = -1 } },
	/* Layout */
	{ MODKEY,                       XK_t,           setlayout,              {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_t,           setlayout,              {.v = &layouts[2]} },
	{ MODKEY,                       XK_f,           togglefakefullscreen,   {0} },
	{ MODKEY|ShiftMask,             XK_f,           togglefullscreen,       {0} },
	/* Sticky window */
	{ MODKEY,                       XK_s,           togglesticky,           {0} },
	{ MODKEY|ShiftMask,             XK_s,           zoom,                   {0} },


	/* stuff */
	{ MODKEY,						XK_c,		   killclient,			   {0} },
	{ MODKEY,						XK_space,      spawn,                  {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY,						XK_BackSpace,	spawn,					SHCMD("sysact") },
	{ MODKEY,           			XK_q,		    quit,				    {1} },
	{ MODKEY,						XK_w,			spawn,					SHCMD("brave") },
	{ MODKEY|ShiftMask,				XK_w,			spawn,					SHCMD("st -e sudo nmtui") },


	/* Movement */
	{ MODKEY,                       XK_Tab,			view,                   {0} },
	{ MODKEY,              			XK_a,			shiftviewclients,       { .i = +1 } },

	/* Scratchpad */
	{ MODKEY,       				XK_Return,     	togglescratch,			{.ui = 0} },
	{ MODKEY,						XK_slash, 	    togglescratch,	       	{.ui = 1} },
	{ MODKEY,                       XK_x,      	    togglescratch,          {.ui = 2 } },
	{ MODKEY|ShiftMask,             XK_x,      	    removescratch,          {.ui = 2 } },
	{ MODKEY,                       XK_z,		    setscratch,             {.ui = 2 } },

	/* Monitor */
	{ MODKEY,                       XK_comma,       focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,      focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,       tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,      tagmon,                 {.i = +1 } },

	/* Tags */
	TAGKEYS(                        XK_1,									0)
	TAGKEYS(                        XK_2,                                  	1)
	TAGKEYS(                        XK_3,                                  	2)
	TAGKEYS(                        XK_4,                                  	3)
	TAGKEYS(                        XK_5,                                  	4)
	TAGKEYS(                        XK_6,                                  	5)
	TAGKEYS(                        XK_7,                                  	6)
	TAGKEYS(                        XK_8,                                  	7)
	TAGKEYS(                        XK_9,                                  	8)
	{ MODKEY,                       XK_0,			view,                   {.ui = ~SPTAGMASK } },
	{ MODKEY|ShiftMask,             XK_0,          	tag,                    {.ui = ~SPTAGMASK } },

	/* Specialkeys */
	{ MODKEY,                       XK_grave,		spawn,					SHCMD("dmenuunicode") },
	{ MODKEY,						XK_Insert,		spawn,					SHCMD("xdotool type $(cat ~/.local/share/larbs/snippets | dmenu -i -l 50 | cut -d' ' -f1)") },
	{ 0,							XK_Print,		spawn,					SHCMD("maim -i $(xdotool getactivewindow) Pictures/scrots/pic-full-$(date '+%y%m%d-%H%M-%S').png") },

	{ MODKEY,						XK_Print,		spawn,					SHCMD("") },
	{ MODKEY,						XK_Delete,		spawn,					SHCMD("") },
	{ MODKEY,						XK_Scroll_Lock,	spawn,					SHCMD("") },

	/* Function keys */
    { MODKEY,						XK_F1,			spawn,					SHCMD("") },
	{ MODKEY,						XK_F2,			spawn,					SHCMD("") },
	{ MODKEY,						XK_F3,			spawn,					SHCMD("") },
	{ MODKEY,						XK_F4,			spawn,					SHCMD("") },

	{ MODKEY,						XK_F5,			spawn,					SHCMD("st -e pulsemixer; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,    					XK_F6,		    spawn,					SHCMD("dmenurecord") },
	{ MODKEY,						XK_F7,		    spawn,					SHCMD("dmenurecord kill") },
	{ MODKEY,						XK_F8,			spawn,					SHCMD("killall screenkey || screenkey &") },

	{ MODKEY,						XK_F9,			spawn,					SHCMD("dmenumount") },
	{ MODKEY,						XK_F10,			spawn,					SHCMD("dmenuumount") },
	{ MODKEY,						XK_F11,			spawn,					SHCMD("displayselect") },
    { MODKEY,			            XK_F12,		    spawn,		            SHCMD("remaps & notify-send \"keyboard remapped.. \"") },

	/* Fn keys */
	{ 0,							XF86XK_AudioMute,		spawn,			SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0, 							XF86XK_AudioRaiseVolume,spawn,			SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
	{ 0, 							XF86XK_AudioLowerVolume,spawn,			SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
	{ 0, 							XF86XK_AudioPrev,		spawn,			SHCMD("mpc prev") },
	{ 0, 							XF86XK_AudioNext,		spawn,			SHCMD("mpc next") },
	{ 0, 							XF86XK_AudioPause,		spawn,			SHCMD("mpc pause") },
	{ 0, 							XF86XK_AudioPlay,		spawn,			SHCMD("mpc play") },
	{ 0, 							XF86XK_AudioStop,		spawn,			SHCMD("mpc stop") },
	{ 0, 							XF86XK_AudioRewind,		spawn,			SHCMD("mpc seek -10") },
	{ 0, 							XF86XK_AudioForward,	spawn,			SHCMD("mpc seek +10") },
	{ 0, 							XF86XK_AudioMicMute,	spawn,			SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ 0, 							XF86XK_Launch1,			spawn,			SHCMD("xset dpms force off") },
	{ 0, 							XF86XK_TouchpadToggle,	spawn,			SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	{ 0, 							XF86XK_TouchpadOff,		spawn,			SHCMD("synclient TouchpadOff=1") },
	{ 0, 							XF86XK_TouchpadOn,		spawn,			SHCMD("synclient TouchpadOff=0") },
	{ 0, 							XF86XK_MonBrightnessUp,	spawn,			SHCMD("xbacklight -inc 5") },
	{ 0, 							XF86XK_MonBrightnessDown,spawn,			SHCMD("xbacklight -dec 5") },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} }, // middle mouse button on title to swap to master
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} }, // right click on tag X to toggle view 

	{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} }, // mod + middle click for floating mode
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} }, // resize window with mod + rigth click and drag
	{ ClkTagBar,            0,                   Button1,        view,           {0} },// view tag x
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} }, // move window to tag x
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} }, //
};

/* static Button buttons[] = { */
/* 	/1* click                event mask           button          function        argument *1/ */
/* 	{ ClkWinTitle,				0,              Button1,        togglewin,      {0} }, */
/* 	{ ClkWinTitle,          	0,				Button3,        showhideclient, {0} }, */
/* 	{ ClkTagBar,				MODKEY,         Button3,        toggletag,      {0} }, // move focused window to selected tag */
/* 	{ ClkLtSymbol,				0,				Button1,        setlayout,      {0} }, // set tile layout */
/* 	{ ClkLtSymbol,				0,              Button3,        setlayout,      {.v = &layouts[2]} }, // set monacle layout */
/* 	{ ClkWinTitle,				0,              Button2,        zoom,           {0} }, // swap to master */
/* 	{ ClkStatusText,        	0,              Button1,        sigdwmblocks,   {.i = 1} }, */
/* 	{ ClkStatusText,        	0,              Button2,        sigdwmblocks,   {.i = 2} }, */
/* 	{ ClkStatusText,        	0,              Button3,        sigdwmblocks,   {.i = 3} }, */
/* 	{ ClkStatusText,        	0,              Button4,        sigdwmblocks,   {.i = 4} }, */
/* 	{ ClkStatusText,        	0,              Button5,        sigdwmblocks,   {.i = 5} }, */
/* 	{ ClkStatusText,        	ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} }, */
/* 	{ ClkStatusText,        	ShiftMask,      Button3,        spawn,          SHCMD("st -e nvim ~/.config/suckless/dwmblocks/config.h") }, */
/* 	{ ClkClientWin,         	MODKEY,         Button1,        movemouse,      {0} }, */
/* 	{ ClkClientWin,         	MODKEY,         Button2,        defaultgaps,	{0} }, */
/* 	{ ClkClientWin,         	MODKEY,         Button3,        resizemouse,    {0} }, */
/* 	{ ClkClientWin,				MODKEY,			Button4,		incrgaps,		{.i = +1} }, */
/* 	{ ClkClientWin,				MODKEY,			Button5,		incrgaps,		{.i = -1} }, */
/* 	{ ClkTagBar,				0,              Button1,        view,           {0} }, */
/* 	{ ClkTagBar,            	0,              Button3,        toggleview,     {0} }, */
/* 	{ ClkTagBar,            	MODKEY,         Button1,        tag,            {0} }, */
/* 	{ ClkTagBar,            	MODKEY,         Button3,        toggletag,      {0} }, */
/* 	{ ClkTagBar,				0,				Button4,		shiftview,		{.i = -1} }, */
/* 	{ ClkTagBar,				0,				Button5,		shiftview,		{.i = 1} }, */
/* 	{ ClkRootWin,				0,				Button2,		togglebar,		{0} }, */
/* }; */

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum                    function */
	{ "focusstack",              focusstack },
	{ "setmfact",                setmfact },
	{ "togglebar",               togglebar },
	{ "incnmaster",              incnmaster },
	{ "togglefloating",          togglefloating },
	{ "focusmon",                focusmon },
	{ "focusurgent",             focusurgent },
	{ "tagmon",                  tagmon },
	{ "zoom",                    zoom },
	{ "view",                    view },
	{ "viewall",                 viewallex },
	{ "viewex",                  viewex },
	{ "toggleview",              toggleview },
	{ "shiftviewclients",        shiftviewclients },
	{ "togglesticky",            togglesticky },
	{ "toggleviewex",            toggleviewex },
	{ "tag",                     tag },
	{ "tagall",                  tagallex },
	{ "tagex",                   tagex },
	{ "toggletag",               toggletag },
	{ "toggletagex",             toggletagex },
	{ "togglealttag",            togglealttag },
	{ "togglefullscreen",        togglefullscreen },
	{ "togglefakefullscreen",    togglefakefullscreen },
	{ "togglescratch",           togglescratch },
	{ "killclient",              killclient },
	{ "xrdb",                    xrdb },
	{ "quit",                    quit },
	{ "setlayout",               setlayout },
	{ "setlayoutex",             setlayoutex },
};

