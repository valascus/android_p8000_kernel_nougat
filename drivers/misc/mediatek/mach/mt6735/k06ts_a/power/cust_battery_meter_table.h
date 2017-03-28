#ifndef _CUST_BATTERY_METER_TABLE_H
#define _CUST_BATTERY_METER_TABLE_H

#include <mach/mt_typedefs.h>

// ============================================================
// define
// ============================================================
#define BAT_NTC_10 1
#define BAT_NTC_47 0

#if (BAT_NTC_10 == 1)
#define RBAT_PULL_UP_R             16900	
#endif

#if (BAT_NTC_47 == 1)
#define RBAT_PULL_UP_R             61900	
#endif

#define RBAT_PULL_UP_VOLT          1800



// ============================================================
// ENUM
// ============================================================

// ============================================================
// structure
// ============================================================

// ============================================================
// typedef
// ============================================================
typedef struct _BATTERY_PROFILE_STRUC
{
    kal_int32 percentage;
    kal_int32 voltage;
} BATTERY_PROFILE_STRUC, *BATTERY_PROFILE_STRUC_P;

typedef struct _R_PROFILE_STRUC
{
    kal_int32 resistance; // Ohm
    kal_int32 voltage;
} R_PROFILE_STRUC, *R_PROFILE_STRUC_P;

typedef enum
{
    T1_0C,
    T2_25C,
    T3_50C
} PROFILE_TEMPERATURE;

// ============================================================
// External Variables
// ============================================================

// ============================================================
// External function
// ============================================================

// ============================================================
// <DOD, Battery_Voltage> Table
// ============================================================
#if (BAT_NTC_10 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[] = {
        {-20,68237},
        {-15,53650},
        {-10,42506},
        { -5,33892},
        {  0,27219},
        {  5,22021},
        { 10,17926},
        { 15,14674},
        { 20,12081},
        { 25,10000},
        { 30,8315},
        { 35,6948},
        { 40,5834},
        { 45,4917},
        { 50,4161},
        { 55,3535},
        { 60,3014}
    };
#endif

#if (BAT_NTC_47 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[] = {
        {-20,483954},
        {-15,360850},
        {-10,271697},
        { -5,206463},
        {  0,158214},
        {  5,122259},
        { 10,95227},
        { 15,74730},
        { 20,59065},
        { 25,47000},
        { 30,37643},
        { 35,30334},
        { 40,24591},
        { 45,20048},
        { 50,16433},
        { 55,13539},
        { 60,11210}        
    };
#endif

// T0 -10C
BATTERY_PROFILE_STRUC battery_profile_t0[] =
{
	{0     , 4342}, 
	{1     , 4316}, 
	{3     , 4296}, 
	{4     , 4278}, 
	{5     , 4262}, 
	{6     , 4246}, 
	{8     , 4230}, 
	{9     , 4215}, 
	{10    , 4201}, 
	{11    , 4187}, 
	{13    , 4174}, 
	{14    , 4160}, 
	{15    , 4146}, 
	{17    , 4133}, 
	{18    , 4119}, 
	{19    , 4106}, 
	{20    , 4096}, 
	{22    , 4086}, 
	{23    , 4076}, 
	{24    , 4062}, 
	{26    , 4044}, 
	{27    , 4023}, 
	{28    , 4003}, 
	{29    , 3985}, 
	{31    , 3971}, 
	{32    , 3959}, 
	{33    , 3950}, 
	{34    , 3942}, 
	{36    , 3935}, 
	{37    , 3928}, 
	{38    , 3920}, 
	{40    , 3912}, 
	{41    , 3904}, 
	{42    , 3895}, 
	{43    , 3887}, 
	{45    , 3879}, 
	{46    , 3872}, 
	{47    , 3864}, 
	{49    , 3857}, 
	{50    , 3850}, 
	{51    , 3844}, 
	{52    , 3838}, 
	{54    , 3832}, 
	{55    , 3826}, 
	{56    , 3821}, 
	{57    , 3815}, 
	{59    , 3810}, 
	{60    , 3806}, 
	{61    , 3802}, 
	{63    , 3798}, 
	{64    , 3794}, 
	{65    , 3791}, 
	{66    , 3788}, 
	{68    , 3786}, 
	{69    , 3783}, 
	{70    , 3780}, 
	{71    , 3778}, 
	{73    , 3775}, 
	{74    , 3773}, 
	{75    , 3770}, 
	{77    , 3768}, 
	{78    , 3765}, 
	{79    , 3761}, 
	{80    , 3758}, 
	{82    , 3755}, 
	{83    , 3751}, 
	{84    , 3747}, 
	{86    , 3743}, 
	{87    , 3738}, 
	{88    , 3734}, 
	{89    , 3730}, 
	{91    , 3725}, 
	{92    , 3721}, 
	{93    , 3716}, 
	{94    , 3713}, 
	{95    , 3711}, 
	{96    , 3709}, 
	{96    , 3708}, 
	{97    , 3706}, 
	{97    , 3705}, 
	{98    , 3703}, 
	{98    , 3702}, 
	{98    , 3701}, 
	{99    , 3700}, 
	{99    , 3699}, 
	{99    , 3698}, 
	{100   , 3696}, 
	{100   , 3400}	       
};      
        
// T1 0C 
BATTERY_PROFILE_STRUC battery_profile_t1[] =
{
	{0     , 4344}, 
	{1     , 4320}, 
	{2     , 4302}, 
	{4     , 4285}, 
	{5     , 4270}, 
	{6     , 4255}, 
	{7     , 4240}, 
	{8     , 4226}, 
	{9     , 4213}, 
	{11    , 4199}, 
	{12    , 4187}, 
	{13    , 4174}, 
	{14    , 4161}, 
	{15    , 4148}, 
	{16    , 4136}, 
	{18    , 4123}, 
	{19    , 4111}, 
	{20    , 4099}, 
	{21    , 4089}, 
	{22    , 4081}, 
	{23    , 4072}, 
	{25    , 4057}, 
	{26    , 4038}, 
	{27    , 4017}, 
	{28    , 3999}, 
	{29    , 3984}, 
	{30    , 3973}, 
	{32    , 3963}, 
	{33    , 3956}, 
	{34    , 3949}, 
	{35    , 3942}, 
	{36    , 3933}, 
	{37    , 3924}, 
	{39    , 3915}, 
	{40    , 3906}, 
	{41    , 3896}, 
	{42    , 3888}, 
	{43    , 3879}, 
	{44    , 3871}, 
	{46    , 3863}, 
	{47    , 3855}, 
	{48    , 3848}, 
	{49    , 3842}, 
	{50    , 3836}, 
	{51    , 3830}, 
	{53    , 3824}, 
	{54    , 3819}, 
	{55    , 3814}, 
	{56    , 3809}, 
	{57    , 3805}, 
	{58    , 3801}, 
	{60    , 3797}, 
	{61    , 3794}, 
	{62    , 3790}, 
	{63    , 3788}, 
	{64    , 3785}, 
	{65    , 3783}, 
	{67    , 3781}, 
	{68    , 3779}, 
	{69    , 3777}, 
	{70    , 3775}, 
	{71    , 3773}, 
	{73    , 3771}, 
	{74    , 3769}, 
	{75    , 3766}, 
	{76    , 3764}, 
	{77    , 3760}, 
	{78    , 3756}, 
	{80    , 3752}, 
	{81    , 3747}, 
	{82    , 3742}, 
	{83    , 3736}, 
	{84    , 3729}, 
	{85    , 3721}, 
	{87    , 3714}, 
	{88    , 3708}, 
	{89    , 3703}, 
	{90    , 3699}, 
	{91    , 3695}, 
	{92    , 3691}, 
	{94    , 3685}, 
	{95    , 3678}, 
	{96    , 3665}, 
	{97    , 3639}, 
	{98    , 3594}, 
	{99    , 3542}, 
	{100   , 3511}, 
	{100   , 3400}       
};           

// T2 25C
BATTERY_PROFILE_STRUC battery_profile_t2[] =
{
	{0    , 4345}, 
	{1    , 4326}, 
	{2    , 4310}, 
	{3    , 4294}, 
	{5    , 4280}, 
	{6    , 4266}, 
	{7    , 4252}, 
	{8    , 4238}, 
	{9    , 4225}, 
	{10   , 4212}, 
	{12   , 4199}, 
	{13   , 4186}, 
	{14   , 4173}, 
	{15   , 4160}, 
	{16   , 4148}, 
	{17   , 4135}, 
	{18   , 4123}, 
	{20   , 4111}, 
	{21   , 4098}, 
	{22   , 4087}, 
	{23   , 4076}, 
	{24   , 4068}, 
	{25   , 4059}, 
	{27   , 4046}, 
	{28   , 4028}, 
	{29   , 4013}, 
	{30   , 4001}, 
	{31   , 3992}, 
	{32   , 3985}, 
	{34   , 3978}, 
	{35   , 3970}, 
	{36   , 3961}, 
	{37   , 3952}, 
	{38   , 3943}, 
	{39   , 3933}, 
	{40   , 3924}, 
	{42   , 3914}, 
	{43   , 3904}, 
	{44   , 3894}, 
	{45   , 3883}, 
	{46   , 3873}, 
	{47   , 3864}, 
	{49   , 3855}, 
	{50   , 3848}, 
	{51   , 3841}, 
	{52   , 3835}, 
	{53   , 3829}, 
	{54   , 3824}, 
	{56   , 3819}, 
	{57   , 3814}, 
	{58   , 3810}, 
	{59   , 3805}, 
	{60   , 3802}, 
	{61   , 3798}, 
	{62   , 3794}, 
	{64   , 3791}, 
	{65   , 3788}, 
	{66   , 3785}, 
	{67   , 3782}, 
	{68   , 3779}, 
	{69   , 3776}, 
	{71   , 3774}, 
	{72   , 3771}, 
	{73   , 3769}, 
	{74   , 3767}, 
	{75   , 3765}, 
	{76   , 3762}, 
	{77   , 3758}, 
	{79   , 3753}, 
	{80   , 3749}, 
	{81   , 3744}, 
	{82   , 3740}, 
	{83   , 3734}, 
	{84   , 3727}, 
	{86   , 3718}, 
	{87   , 3710}, 
	{88   , 3699}, 
	{89   , 3692}, 
	{90   , 3689}, 
	{91   , 3688}, 
	{93   , 3687}, 
	{94   , 3685}, 
	{95   , 3681}, 
	{96   , 3670}, 
	{97   , 3630}, 
	{98   , 3567}, 
	{99   , 3476}, 
	{100  , 3400}	       
};     

// T3 50C
BATTERY_PROFILE_STRUC battery_profile_t3[] =
{
	{0   , 4345}, 
	{1   , 4327}, 
	{2   , 4311}, 
	{3   , 4295}, 
	{5   , 4280}, 
	{6   , 4266}, 
	{7   , 4252}, 
	{8   , 4238}, 
	{9   , 4225}, 
	{10  , 4212}, 
	{12  , 4199}, 
	{13  , 4186}, 
	{14  , 4173}, 
	{15  , 4160}, 
	{16  , 4147}, 
	{17  , 4135}, 
	{18  , 4122}, 
	{20  , 4110}, 
	{21  , 4098}, 
	{22  , 4086}, 
	{23  , 4075}, 
	{24  , 4063}, 
	{25  , 4052}, 
	{26  , 4041}, 
	{28  , 4030}, 
	{29  , 4020}, 
	{30  , 4009}, 
	{31  , 3999}, 
	{32  , 3990}, 
	{33  , 3980}, 
	{35  , 3971}, 
	{36  , 3962}, 
	{37  , 3953}, 
	{38  , 3944}, 
	{39  , 3936}, 
	{40  , 3927}, 
	{41  , 3919}, 
	{43  , 3910}, 
	{44  , 3900}, 
	{45  , 3890}, 
	{46  , 3879}, 
	{47  , 3867}, 
	{48  , 3857}, 
	{50  , 3849}, 
	{51  , 3841}, 
	{52  , 3835}, 
	{53  , 3829}, 
	{54  , 3823}, 
	{55  , 3818}, 
	{56  , 3813}, 
	{58  , 3809}, 
	{59  , 3804}, 
	{60  , 3800}, 
	{61  , 3796}, 
	{62  , 3793}, 
	{63  , 3789}, 
	{65  , 3786}, 
	{66  , 3783}, 
	{67  , 3780}, 
	{68  , 3777}, 
	{69  , 3774}, 
	{70  , 3771}, 
	{71  , 3767}, 
	{73  , 3763}, 
	{74  , 3757}, 
	{75  , 3751}, 
	{76  , 3747}, 
	{77  , 3743}, 
	{78  , 3738}, 
	{79  , 3733}, 
	{81  , 3729}, 
	{82  , 3725}, 
	{83  , 3721}, 
	{84  , 3714}, 
	{85  , 3706}, 
	{86  , 3698}, 
	{88  , 3689}, 
	{89  , 3679}, 
	{90  , 3676}, 
	{91  , 3674}, 
	{92  , 3673}, 
	{93  , 3672}, 
	{94  , 3670}, 
	{96  , 3662}, 
	{97  , 3632}, 
	{98  , 3577}, 
	{99  , 3499}, 
	{100 , 3400}       
};           

// battery profile for actual temperature. The size should be the same as T1, T2 and T3
BATTERY_PROFILE_STRUC battery_profile_temperature[] =
{
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}
};    

// ============================================================
// <Rbat, Battery_Voltage> Table
// ============================================================
// T0 -10C
R_PROFILE_STRUC r_profile_t0[] =
{
	{582    , 4342}, 
	{582    , 4316}, 
	{586    , 4296}, 
	{582    , 4278}, 
	{577    , 4262}, 
	{571    , 4246}, 
	{564    , 4230}, 
	{559    , 4215}, 
	{551    , 4201}, 
	{546    , 4187}, 
	{540    , 4174}, 
	{535    , 4160}, 
	{529    , 4146}, 
	{525    , 4133}, 
	{521    , 4119}, 
	{516    , 4106}, 
	{513    , 4096}, 
	{511    , 4086}, 
	{509    , 4076}, 
	{507    , 4062}, 
	{502    , 4044}, 
	{493    , 4023}, 
	{488    , 4003}, 
	{485    , 3985}, 
	{483    , 3971}, 
	{481    , 3959}, 
	{482    , 3950}, 
	{483    , 3942}, 
	{484    , 3935}, 
	{484    , 3928}, 
	{483    , 3920}, 
	{483    , 3912}, 
	{482    , 3904}, 
	{481    , 3895}, 
	{481    , 3887}, 
	{481    , 3879}, 
	{480    , 3872}, 
	{480    , 3864}, 
	{481    , 3857}, 
	{481    , 3850}, 
	{482    , 3844}, 
	{483    , 3838}, 
	{484    , 3832}, 
	{485    , 3826}, 
	{486    , 3821}, 
	{488    , 3815}, 
	{489    , 3810}, 
	{491    , 3806}, 
	{492    , 3802}, 
	{495    , 3798}, 
	{498    , 3794}, 
	{501    , 3791}, 
	{504    , 3788}, 
	{507    , 3786}, 
	{510    , 3783}, 
	{514    , 3780}, 
	{518    , 3778}, 
	{523    , 3775}, 
	{527    , 3773}, 
	{533    , 3770}, 
	{540    , 3768}, 
	{547    , 3765}, 
	{555    , 3761}, 
	{563    , 3758}, 
	{573    , 3755}, 
	{584    , 3751}, 
	{596    , 3747}, 
	{610    , 3743}, 
	{625    , 3738}, 
	{642    , 3734}, 
	{659    , 3730}, 
	{678    , 3725}, 
	{696    , 3721}, 
	{714    , 3716}, 
	{714    , 3713}, 
	{712    , 3711}, 
	{710    , 3709}, 
	{709    , 3708}, 
	{707    , 3706}, 
	{705    , 3705}, 
	{705    , 3703}, 
	{702    , 3702}, 
	{702    , 3701}, 
	{702    , 3700}, 
	{701    , 3699}, 
	{698    , 3698}, 
	{699    , 3696}, 
	{402    , 3400}       
};      

// T1 0C
R_PROFILE_STRUC r_profile_t1[] =
{
	{309   , 4344}, 
	{309   , 4320}, 
	{310   , 4302}, 
	{310   , 4285}, 
	{310   , 4270}, 
	{309   , 4255}, 
	{308   , 4240}, 
	{307   , 4226}, 
	{307   , 4213}, 
	{306   , 4199}, 
	{305   , 4187}, 
	{305   , 4174}, 
	{305   , 4161}, 
	{305   , 4148}, 
	{304   , 4136}, 
	{304   , 4123}, 
	{304   , 4111}, 
	{303   , 4099}, 
	{304   , 4089}, 
	{306   , 4081}, 
	{309   , 4072}, 
	{309   , 4057}, 
	{306   , 4038}, 
	{303   , 4017}, 
	{300   , 3999}, 
	{299   , 3984}, 
	{299   , 3973}, 
	{299   , 3963}, 
	{300   , 3956}, 
	{302   , 3949}, 
	{301   , 3942}, 
	{300   , 3933}, 
	{298   , 3924}, 
	{297   , 3915}, 
	{296   , 3906}, 
	{296   , 3896}, 
	{295   , 3888}, 
	{295   , 3879}, 
	{294   , 3871}, 
	{294   , 3863}, 
	{294   , 3855}, 
	{295   , 3848}, 
	{295   , 3842}, 
	{296   , 3836}, 
	{297   , 3830}, 
	{297   , 3824}, 
	{299   , 3819}, 
	{300   , 3814}, 
	{301   , 3809}, 
	{302   , 3805}, 
	{303   , 3801}, 
	{305   , 3797}, 
	{306   , 3794}, 
	{307   , 3790}, 
	{309   , 3788}, 
	{311   , 3785}, 
	{313   , 3783}, 
	{315   , 3781}, 
	{317   , 3779}, 
	{320   , 3777}, 
	{322   , 3775}, 
	{326   , 3773}, 
	{329   , 3771}, 
	{333   , 3769}, 
	{338   , 3766}, 
	{342   , 3764}, 
	{347   , 3760}, 
	{353   , 3756}, 
	{360   , 3752}, 
	{367   , 3747}, 
	{376   , 3742}, 
	{386   , 3736}, 
	{397   , 3729}, 
	{411   , 3721}, 
	{428   , 3714}, 
	{447   , 3708}, 
	{473   , 3703}, 
	{503   , 3699}, 
	{542   , 3695}, 
	{593   , 3691}, 
	{646   , 3685}, 
	{688   , 3678}, 
	{724   , 3665}, 
	{759   , 3639}, 
	{800   , 3594}, 
	{842   , 3542}, 
	{811   , 3511}, 
	{702   , 3400}      
};     

// T2 25C
R_PROFILE_STRUC r_profile_t2[] =
{
	{132   , 4345}, 
	{132   , 4326}, 
	{132   , 4310}, 
	{132   , 4294}, 
	{132   , 4280}, 
	{132   , 4266}, 
	{132   , 4252}, 
	{132   , 4238}, 
	{132   , 4225}, 
	{133   , 4212}, 
	{133   , 4199}, 
	{134   , 4186}, 
	{134   , 4173}, 
	{134   , 4160}, 
	{135   , 4148}, 
	{136   , 4135}, 
	{136   , 4123}, 
	{137   , 4111}, 
	{138   , 4098}, 
	{139   , 4087}, 
	{139   , 4076}, 
	{140   , 4068}, 
	{142   , 4059}, 
	{142   , 4046}, 
	{141   , 4028}, 
	{142   , 4013}, 
	{142   , 4001}, 
	{143   , 3992}, 
	{144   , 3985}, 
	{145   , 3978}, 
	{145   , 3970}, 
	{145   , 3961}, 
	{145   , 3952}, 
	{145   , 3943}, 
	{145   , 3933}, 
	{144   , 3924}, 
	{144   , 3914}, 
	{142   , 3904}, 
	{141   , 3894}, 
	{138   , 3883}, 
	{137   , 3873}, 
	{135   , 3864}, 
	{134   , 3855}, 
	{133   , 3848}, 
	{132   , 3841}, 
	{132   , 3835}, 
	{132   , 3829}, 
	{132   , 3824}, 
	{132   , 3819}, 
	{132   , 3814}, 
	{132   , 3810}, 
	{132   , 3805}, 
	{133   , 3802}, 
	{133   , 3798}, 
	{133   , 3794}, 
	{134   , 3791}, 
	{134   , 3788}, 
	{134   , 3785}, 
	{134   , 3782}, 
	{134   , 3779}, 
	{134   , 3776}, 
	{134   , 3774}, 
	{135   , 3771}, 
	{134   , 3769}, 
	{134   , 3767}, 
	{134   , 3765}, 
	{134   , 3762}, 
	{133   , 3758}, 
	{133   , 3753}, 
	{133   , 3749}, 
	{133   , 3744}, 
	{134   , 3740}, 
	{134   , 3734}, 
	{134   , 3727}, 
	{134   , 3718}, 
	{135   , 3710}, 
	{134   , 3699}, 
	{133   , 3692}, 
	{134   , 3689}, 
	{136   , 3688}, 
	{139   , 3687}, 
	{143   , 3685}, 
	{148   , 3681}, 
	{150   , 3670}, 
	{146   , 3630}, 
	{150   , 3567}, 
	{159   , 3476}, 
	{183   , 3400}        
}; 

// T3 50C
R_PROFILE_STRUC r_profile_t3[] =
{
	{116  , 4345}, 
	{116  , 4327}, 
	{116  , 4311}, 
	{115  , 4295}, 
	{115  , 4280}, 
	{115  , 4266}, 
	{115  , 4252}, 
	{115  , 4238}, 
	{115  , 4225}, 
	{115  , 4212}, 
	{116  , 4199}, 
	{116  , 4186}, 
	{116  , 4173}, 
	{116  , 4160}, 
	{117  , 4147}, 
	{117  , 4135}, 
	{117  , 4122}, 
	{118  , 4110}, 
	{118  , 4098}, 
	{118  , 4086}, 
	{119  , 4075}, 
	{119  , 4063}, 
	{120  , 4052}, 
	{120  , 4041}, 
	{120  , 4030}, 
	{121  , 4020}, 
	{122  , 4009}, 
	{122  , 3999}, 
	{123  , 3990}, 
	{123  , 3980}, 
	{124  , 3971}, 
	{125  , 3962}, 
	{125  , 3953}, 
	{126  , 3944}, 
	{127  , 3936}, 
	{127  , 3927}, 
	{127  , 3919}, 
	{127  , 3910}, 
	{127  , 3900}, 
	{125  , 3890}, 
	{123  , 3879}, 
	{120  , 3867}, 
	{118  , 3857}, 
	{117  , 3849}, 
	{117  , 3841}, 
	{117  , 3835}, 
	{117  , 3829}, 
	{117  , 3823}, 
	{117  , 3818}, 
	{117  , 3813}, 
	{117  , 3809}, 
	{118  , 3804}, 
	{118  , 3800}, 
	{119  , 3796}, 
	{119  , 3793}, 
	{120  , 3789}, 
	{120  , 3786}, 
	{121  , 3783}, 
	{121  , 3780}, 
	{122  , 3777}, 
	{122  , 3774}, 
	{122  , 3771}, 
	{121  , 3767}, 
	{120  , 3763}, 
	{118  , 3757}, 
	{117  , 3751}, 
	{118  , 3747}, 
	{118  , 3743}, 
	{118  , 3738}, 
	{117  , 3733}, 
	{118  , 3729}, 
	{118  , 3725}, 
	{119  , 3721}, 
	{119  , 3714}, 
	{119  , 3706}, 
	{119  , 3698}, 
	{119  , 3689}, 
	{117  , 3679}, 
	{117  , 3676}, 
	{119  , 3674}, 
	{121  , 3673}, 
	{124  , 3672}, 
	{127  , 3670}, 
	{130  , 3662}, 
	{124  , 3632}, 
	{124  , 3577}, 
	{127  , 3499}, 
	{134  , 3400}     
}; 

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUC r_profile_temperature[] =
{
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}, 
	{0 , 0}
};    

// ============================================================
// function prototype
// ============================================================
int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUC_P fgauge_get_profile(kal_uint32 temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUC_P fgauge_get_profile_r_table(kal_uint32 temperature);

#endif	//#ifndef _CUST_BATTERY_METER_TABLE_H

