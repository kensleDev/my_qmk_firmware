# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu
COMBO_ENABLE = yes
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
API_SYSEX_ENABLE = no

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend

LAYOUTS = ortho_4x12 planck_mit
LAYOUTS_HAS_RGB = no


# There are 83 pairs of alphabetical letters that do not appear in the wordlist:
# bq bz cf cj cv cx fq fv fx fz gq gv gx hx hz jb jd jf jg jh jl jm jp jq jr js jt jv jw jx jy jz kq kx kz mx mz pq pv px qb qc qd qf qg qh qj qk ql qm qn qp qq qv qw qx qy qz sx tq vb vf vh vj vk vm vp vq vw vx wq wv wx xd xj xk xr xz yq yy zf zr zx

# There are 593 pairs of alphabetical letters that do appear in the wordlist (since that was part of your original question and no one seems to have answered it):
# aa ab ac ad ae af ag ah ai aj ak al am an ao ap aq ar as at au av aw ax ay az ba bb bc bd be bf bg bh bi bj bk bl bm bn bo bp br bs bt bu bv bw bx by ca cb cc cd ce cg ch ci ck cl cm cn co cp cq cr cs ct cu cw cy cz da db dc dd de df dg dh di dj dk dl dm dn do dp dq dr ds dt du dv dw dx dy dz ea eb ec ed ee ef eg eh ei ej ek el em en eo ep eq er es et eu ev ew ex ey ez fa fb fc fd fe ff fg fh fi fj fk fl fm fn fo fp fr fs ft fu fw fy ga gb gc gd ge gf gg gh gi gj gk gl gm gn go gp gr gs gt gu gw gy gz ha hb hc hd he hf hg hh hi hj hk hl hm hn ho hp hq hr hs ht hu hv hw hy ia ib ic id ie if ig ih ii ij ik il im in io ip iq ir is it iu iv iw ix iy iz ja jc je ji jj jk jn jo ju ka kb kc kd ke kf kg kh ki kj kk kl km kn ko kp kr ks kt ku kv kw ky la lb lc ld le lf lg lh li lj lk ll lm ln lo lp lq lr ls lt lu lv lw lx ly lz ma mb mc md me mf mg mh mi mj mk ml mm mn mo mp mq mr ms mt mu mv mw my na nb nc nd ne nf ng nh ni nj nk nl nm nn no np nq nr ns nt nu nv nw nx ny nz oa ob oc od oe of og oh oi oj ok ol om on oo op oq or os ot ou ov ow ox oy oz pa pb pc pd pe pf pg ph pi pj pk pl pm pn po pp pr ps pt pu pw py pz qa qe qi qo qr qs qt qu ra rb rc rd re rf rg rh ri rj rk rl rm rn ro rp rq rr rs rt ru rv rw rx ry rz sa sb sc sd se sf sg sh si sj sk sl sm sn so sp sq sr ss st su sv sw sy sz ta tb tc td te tf tg th ti tj tk tl tm tn to tp tr ts tt tu tv tw tx ty tz ua ub uc ud ue uf ug uh ui uj uk ul um un uo up uq ur us ut uu uv uw ux uy uz va vc vd ve vg vi vl vn vo vr vs vt vu vv vy vz wa wb wc wd we wf wg wh wi wj wk wl wm wn wo wp wr ws wt wu ww wy wz xa xb xc xe xf xg xh xi xl xm xn xo xp xq xs xt xu xv xw xx xy ya yb yc yd ye yf yg yh yi yj yk yl ym yn yo yp yr ys yt yu yv yw yx yz za zb zc zd ze zg zh zi zj zk zl zm zn zo zp zq zs zt zu zv zw zy zz

# Efficiency part: In order to reduce having to search through all the pairs, I deleted them as I went along. So, after a number of rounds, instead of searching through 676 pairs to see which ones matched and which ones didn't, I had to search through a significantly less amount. Once I have all the non-matches (easier to search non-matches first), I then remake the list and remove the non-matches to get all the matches. Efficient.

