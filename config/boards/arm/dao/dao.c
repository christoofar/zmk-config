/*
 * Copyright (c) 2021 Rafael Yumagulov
 *
 * SPDX-License-Identifier: MIT
 */

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>

#define DEF 0
#define CAN 1
#define LWR 2
#define RSE 3
#define ADJ 4

&lt { quick_tap_ms = <200>; };
&mt { quick_tap_ms = <200>; };

/ {
    macros {
        zed_alt_tab: zed_alt_tab {
            label = "ZM_zed_alt_tab";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&macro_press &kp LALT>
                , <&macro_tap &kp TAB>
                , <&macro_release &kp LALT>
                ;
        };
    };
};

/ {
    combos {
        compatible = "zmk,combos";
        combo_LPAR {
            timeout-ms = <50>;
            key-positions = <17 18>;
            bindings = <&kp LPAR>;
        };
        combo_RPAR {
            timeout-ms = <50>;
            key-positions = <18 19>;
            bindings = <&kp RPAR>;
        };
        combo_LCURLY {
            timeout-ms = <50>;
            key-positions = <21 22>;
            bindings = <&kp LEFT_BRACE>;
        };
        combo_RCURLY {
            timeout-ms = <50>;
            key-positions = <22 23>;
            bindings = <&kp RIGHT_BRACE>;
        };
        combo_LBRACKET {
            timeout-ms = <50>;
            key-positions = <33 34>;
            bindings = <&kp LEFT_BRACKET>;
        };	
        combo_RBRACKET {
            timeout-ms = <50>;
            key-positions = <34 35>;
            bindings = <&kp RIGHT_BRACKET>;
        };
        combo_PAGEUP {
            timeout-ms = <50>;
            key-positions = <7 8>;
            bindings = <&kp PAGE_UP>;
        }; 
       combo_PAGEDOWN {
            timeout-ms = <50>;
            key-positions = <20 21>;
            bindings = <&kp PAGE_DOWN>;
        };
        combo_HOME {
            timeout-ms = <50>;
            key-positions = <7 8 9>;
            bindings = <&kp HOME>;
        };
        combo_END {
            timeout-ms = <50>;
            key-positions = <20 21 22>;
            bindings = <&kp END>;
        };
        combo_LGUI {
            timeout-ms = <50>;
            key-positions = <32 33>;
            bindings = <&kp LGUI>;
        };
        combo_RGUI {
	    // This is a quick way to strike the Compose key
	    // (when the Compose key is mapped to RGUI
            timeout-ms = <50>;
            key-positions = <14 15 16 17>;
            bindings = <&kp RGUI>;
        };	
    };
};

/ {
        keymap {
                compatible = "zmk,keymap";

		default_layer {
// --------------------------------------------------------------------------------------------------------
// |      | ALT/TAB  |  Q  |  D  |  R  |  W  |  B  |     |  J  |  F   |  U  |  P  |  ;  |  ALT/DEL   |    |
//        | CTRL     |  A  |  S  |  H  |  T  |  G  |     |  Y  |  N   |  E  |  O  |  I  |  CTRL/'    |
//        | LALT     |  Z  |  X  |  M  |  C  |  V  |     |  K  |  L   |  ,  |  .  |  /  |  ESC       |
//                           | LGUI | LWR | SH ENT |     | SPC | RSE | RSE |
                        bindings = <
   &none    &mt LALT TAB   &kp Q &kp D &kp R &kp W &kp B &kp J         &kp F  &kp U     &kp P   &kp SEMI    &mt RALT BSPC &none
            &kp LCTRL      &kp A &kp S &kp H &kp T &kp G &kp Y         &kp N  &kp E     &kp O   &kp I       &mt RCTRL SQT
            &kp LALT       &kp Z &kp X &kp M &kp C &kp V &kp K         &kp L  &kp COMMA &kp DOT &kp FSLH    &kp ESC
                               &kp LGUI &mo LWR &mt LSHFT RET          &kp SPACE  &mo RSE  &lt RSE DEL
                        >;
                };
		canary_layer {
// -------------------------------------------------------------------------------------------------------
// |      | ALT/TAB  |  W  |  L  |p  Y  |  P  |  B  |     |  Z  |  F   |  O  |  U  |  '  |  ALT/DEL |     |
//        | CTRL     |  C  |  R  |  S  |  T  |  G  |     |  M  |  N   |  E  |  I  |  A  |  CTRL/;  |
//        | LALT     |  Q  |  J  |  V  |  D  |  K  |     |  X  |  H   |  /  |  ,  |  .  |  ESC     |
//                           | LGUI | LWR | SH ENT |     | SPC | RSE  | RSE |
                        bindings = <
   &none    &mt LALT TAB &kp W &kp L &kp Y &kp P &kp B            &kp Z  &kp F  &kp O     &kp U     &kp SQT     &mt RALT BSPC  &none
            &kp LCTRL    &kp C &kp R &kp S &kp T &kp G            &kp M  &kp N  &kp E     &kp I     &kp A       &mt RCTRL SEMI
            &kp LALT     &kp Q &kp J &kp V &kp D &kp K            &kp X  &kp H  &kp FSLH  &kp COMMA &kp DOT     &kp ESC
                         &kp LGUI &mo LWR &mt LSHFT RET       &kp SPACE  &mo RSE  &lt RSE DEL
                        >;
                };		
                lower_layer {
// ---------------------------------------------------------------------------------------------------
// |     |  ALT/TAB |      |      |  UP   |       |      |     |     |  7 | 8 |  9 |     |     |     |
//       |  CTRL    |      | LEFT | DOWN  | RGHT  |      |     | SPC |  4 | 5 |  6 |  +  | DEL |
//       |  LALT    |      |      |DEFAULT|CANARY | NUM  |     |  0  |  1 | 2 |  3 |  /  |  .  |
//                                | GUI |     | SHFT |        | ENT |     | ALT |
                        bindings = <
   &trans &zed_alt_tab   &none    &none   &kp UP    &kp none   &none                &none     &kp N7   &kp N8   &kp N9   &none          &none &none
          &kp LCTRL      &none    &kp LEFT &kp DOWN &kp RIGHT  &none                &kp SPACE &kp N4   &kp N5   &kp N6   &kp KP_PLUS    &kp DEL
          &kp LALT       &none    &none    &to DEF  &to CAN    &kp KP_NUM           &kp N0    &kp N1   &kp N2   &kp N3   &kp KP_SLASH   &kp KP_DOT
                                           &trans   &trans     &kp LSHFT            &kp ENTER &mo ADJ &trans
                        >;
                };
                raise_layer {
// ---------------------------------------------------------------------------------------------------
// |     | NMLK |  !  |  @  |  #  |  $  |  %  |          |  ^  |  &  |  *  |     | SCLK | CAPS |     |
//       | CTRL |     |     |     |     |     |          |  -  |  =  |  UP |     |  \   |   `  |
//       |      |     |     |     |     |     |          |  _  |  +  | DOWN|     |  |   |   ~  |
//                          |     |     | ADJ |          | ADJ |     |     |
                        bindings = <
   &trans &kp KP_NUM   &kp EXCL    &kp AT     &kp POUND &kp DOLLAR &kp PERCENT              &kp CARET &kp AMPERSAND &kp STAR  &none     &kp SLCK  &kp CAPS &trans
          &kp LCTRL    &none       &none      &none     &none      &none                    &kp MINUS &kp EQUAL     &kp UP    &none     &kp BSLH  &kp GRAVE
          &trans       &none       &none      &none     &to CAN    &none                    &kp UNDER &kp PLUS      &kp DOWN  &none     &kp PIPE  &kp TILDE
                                                           &trans &trans &lt ADJ RET        &lt ADJ ESC &trans &trans
                        >;
                };
                adjust_layer {
// -----------------------------------------------------------------------------------------
// | RST | BLDR |     |     |     |     |     |   |     |     |     |     |     | BLDR | RST |
//       | BTCLR| BT0 | BT1 | BT2 | BT3 | BT4 |   | BT4 | BT3 | BT2 | BT1 | BT0 | BTCLR|
//       |      |     |     |     |     |     |   |     |     |     |     |     |      |
//                          |     |     |     |   |     |     |     |
                        bindings = <
   &reset &kp F1      &kp F2       &kp F3       &kp F4       &kp F5        &kp F6             &kp F7       &kp F8       &kp F9       &kp F10      &kp F11       &kp F12 &reset
          &bt BT_CLR  &bt BT_SEL 0 &bt BT_SEL 1 &bt BT_SEL 2 &bt BT_SEL 3  &bt BT_SEL 4       &bt BT_SEL 4 &bt BT_SEL 3 &bt BT_SEL 2 &bt BT_SEL 1 &bt BT_SEL 0  &none
          &bootloader &none        &none        &none        &none         &none              &none        &none        &none        &none        &none         &bootloader
                                                                    &trans &none &trans   &trans &none &trans
                        >;
                };
        };
};

