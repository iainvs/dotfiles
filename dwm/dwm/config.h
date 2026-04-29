/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMonoNL Nerd Font:size=10" };
static const char dmenufont[]       = "JetBrainsMonoNL Nerd Font:size=10";
static const char black[]           = "#000000";
static const char darkGray[]        = "#1d2021";
static const char lightGray[]       = "#3c383c";
static const char white[]           = "#fbf1c7";
static const char dilaw[]           = "#dfab01";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { white, black, black },
	[SchemeSel]  = { black, dilaw,  dilaw  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3" };

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
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 30;  /* refresh rate (per second) for client move/resize */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-b", "-nb", black, "-nf", white, "-sb", dilaw, "-sf", black, NULL };
static const char *stcmd[]  = { "st", "-e", "sh", "-c", "fastfetch; exec $SHELL", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } }, // start dmenu
	{ MODKEY,                       XK_q,      spawn,          {.v = stcmd } }, //start st
  { MODKEY,                       XK_r,      quit,           {0} }, // reload dwm in config
	{ MODKEY,                       XK_b,      togglebar,      {0} }, // toggle bar
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } }, // cycle focus forward
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, // cycle focus back
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } }, // add master client
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } }, // remove master client
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} }, // shrink master
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} }, // grow master
	{ MODKEY,                       XK_Return, zoom,           {0} }, // zoom to master
	{ MODKEY,                       XK_Tab,    view,           {0} }, // view previous tag
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, // change to tile 
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} }, // change to fload
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} }, //change to monocle
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} }, // toggle floating
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } }, // view all tags
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, // tag client to all tags
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } }, // focus prev monitor
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } }, // focus next monitor
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } }, // send to prev monitor
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } }, // send to next monitor
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,                       XK_c,      killclient,     {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = stcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

