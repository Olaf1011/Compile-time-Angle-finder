#pragma once

#include <array>
#include <iostream>
#include "Factorial.hpp"

#define PI 3.14159265
class Sin;
class Cos;

template<int A, class Type>
struct AngleFinder;

template<>
struct AngleFinder<0, Sin>
{
	static constexpr double value = 0.0;
	double operator()() const { return value; }
};

template<int X>
struct AngleFinder<X, Sin>
{
	static constexpr double x = (static_cast<double>(X) * PI / 180.0);
	static constexpr double value = x - (x * x * x) / Factorial<3>::result + (x * x * x * x * x) / Factorial<5>::result - (x * x * x * x * x * x * x) / Factorial<7>::result;
	const double operator()() const { return value; }
};

template<int A>
struct AngleFinder<A, Cos>
{
	const double value = cosf(static_cast<double>(A) * PI / 180);
	double operator()() const { return value; }
};


template <size_t N, class Type>
struct Angles
{
	Angles() { Fill(this); };
	double& operator[](const size_t i)
	{
		return ms_angles[i];
	}
	const double& operator[](const size_t i) const
	{
		return ms_angles[i];
	}

	template <size_t I = 0>
	static constexpr void Fill(Angles* ptr)
	{
		// Fill out our angle array
		ptr->ms_angles[I] = AngleFinder<static_cast<int>(I), Type>()();
		// recurse upwards
		if constexpr (I + 1 < N + 1) Angles<N, Type>::Fill<I + 1>(ptr);
	}
	static std::array<double, N + 1> ms_angles;
private:
};

struct CosAngles
{
	CosAngles()
	{
		for (int i = 0; i < 361; ++i)
		{
			m_angles[i] = cos(i);
		}
	}

	std::array<double, 361> m_angles{};
};

static Angles<360, Sin> s_sinAngles;
//static Angles<360, Cos> s_cosAngles;
//static std::array<double, 361> s_sinManualAngles;


inline void SinPrint(int i)
{
	std::cout << sin(i * PI / 180) << std::endl;
}

inline void LookUpFunc(int i)
{
	std::cout << s_sinAngles[i] << std::endl;
}

inline void LookUp(int i)
{
	std::cout << s_sinAngles.ms_angles[i] << std::endl;
}

//
//inline void WTFFunc()
//{
//	s_sinManualAngles[0] = AngleFinder<0, Sin>()();
//	s_sinManualAngles[1] = AngleFinder<1, Sin>()();
//	s_sinManualAngles[2] = AngleFinder<2, Sin>()();
//	s_sinManualAngles[3] = AngleFinder<3, Sin>()();
//	s_sinManualAngles[4] = AngleFinder<4, Sin>()();
//	s_sinManualAngles[5] = AngleFinder<5, Sin>()();
//	s_sinManualAngles[6] = AngleFinder<6, Sin>()();
//	s_sinManualAngles[7] = AngleFinder<7, Sin>()();
//	s_sinManualAngles[8] = AngleFinder<8, Sin>()();
//	s_sinManualAngles[9] = AngleFinder<9, Sin>()();
//	s_sinManualAngles[10] = AngleFinder<10, Sin>()();
//	s_sinManualAngles[11] = AngleFinder<11, Sin>()();
//	s_sinManualAngles[12] = AngleFinder<12, Sin>()();
//	s_sinManualAngles[13] = AngleFinder<13, Sin>()();
//	s_sinManualAngles[14] = AngleFinder<14, Sin>()();
//	s_sinManualAngles[15] = AngleFinder<15, Sin>()();
//	s_sinManualAngles[16] = AngleFinder<16, Sin>()();
//	s_sinManualAngles[17] = AngleFinder<17, Sin>()();
//	s_sinManualAngles[18] = AngleFinder<18, Sin>()();
//	s_sinManualAngles[19] = AngleFinder<19, Sin>()();
//	s_sinManualAngles[20] = AngleFinder<20, Sin>()();
//	s_sinManualAngles[21] = AngleFinder<21, Sin>()();
//	s_sinManualAngles[22] = AngleFinder<22, Sin>()();
//	s_sinManualAngles[23] = AngleFinder<23, Sin>()();
//	s_sinManualAngles[24] = AngleFinder<24, Sin>()();
//	s_sinManualAngles[25] = AngleFinder<25, Sin>()();
//	s_sinManualAngles[26] = AngleFinder<26, Sin>()();
//	s_sinManualAngles[27] = AngleFinder<27, Sin>()();
//	s_sinManualAngles[28] = AngleFinder<28, Sin>()();
//	s_sinManualAngles[29] = AngleFinder<29, Sin>()();
//	s_sinManualAngles[30] = AngleFinder<30, Sin>()();
//	s_sinManualAngles[31] = AngleFinder<31, Sin>()();
//	s_sinManualAngles[32] = AngleFinder<32, Sin>()();
//	s_sinManualAngles[33] = AngleFinder<33, Sin>()();
//	s_sinManualAngles[34] = AngleFinder<34, Sin>()();
//	s_sinManualAngles[35] = AngleFinder<35, Sin>()();
//	s_sinManualAngles[36] = AngleFinder<36, Sin>()();
//	s_sinManualAngles[37] = AngleFinder<37, Sin>()();
//	s_sinManualAngles[38] = AngleFinder<38, Sin>()();
//	s_sinManualAngles[39] = AngleFinder<39, Sin>()();
//	s_sinManualAngles[40] = AngleFinder<40, Sin>()();
//	s_sinManualAngles[41] = AngleFinder<41, Sin>()();
//	s_sinManualAngles[42] = AngleFinder<42, Sin>()();
//	s_sinManualAngles[43] = AngleFinder<43, Sin>()();
//	s_sinManualAngles[44] = AngleFinder<44, Sin>()();
//	s_sinManualAngles[45] = AngleFinder<45, Sin>()();
//	s_sinManualAngles[46] = AngleFinder<46, Sin>()();
//	s_sinManualAngles[47] = AngleFinder<47, Sin>()();
//	s_sinManualAngles[48] = AngleFinder<48, Sin>()();
//	s_sinManualAngles[49] = AngleFinder<49, Sin>()();
//	s_sinManualAngles[50] = AngleFinder<50, Sin>()();
//	s_sinManualAngles[51] = AngleFinder<51, Sin>()();
//	s_sinManualAngles[52] = AngleFinder<52, Sin>()();
//	s_sinManualAngles[53] = AngleFinder<53, Sin>()();
//	s_sinManualAngles[54] = AngleFinder<54, Sin>()();
//	s_sinManualAngles[55] = AngleFinder<55, Sin>()();
//	s_sinManualAngles[56] = AngleFinder<56, Sin>()();
//	s_sinManualAngles[57] = AngleFinder<57, Sin>()();
//	s_sinManualAngles[58] = AngleFinder<58, Sin>()();
//	s_sinManualAngles[59] = AngleFinder<59, Sin>()();
//	s_sinManualAngles[60] = AngleFinder<60, Sin>()();
//	s_sinManualAngles[61] = AngleFinder<61, Sin>()();
//	s_sinManualAngles[62] = AngleFinder<62, Sin>()();
//	s_sinManualAngles[63] = AngleFinder<63, Sin>()();
//	s_sinManualAngles[64] = AngleFinder<64, Sin>()();
//	s_sinManualAngles[65] = AngleFinder<65, Sin>()();
//	s_sinManualAngles[66] = AngleFinder<66, Sin>()();
//	s_sinManualAngles[67] = AngleFinder<67, Sin>()();
//	s_sinManualAngles[68] = AngleFinder<68, Sin>()();
//	s_sinManualAngles[69] = AngleFinder<69, Sin>()();
//	s_sinManualAngles[70] = AngleFinder<70, Sin>()();
//	s_sinManualAngles[71] = AngleFinder<71, Sin>()();
//	s_sinManualAngles[72] = AngleFinder<72, Sin>()();
//	s_sinManualAngles[73] = AngleFinder<73, Sin>()();
//	s_sinManualAngles[74] = AngleFinder<74, Sin>()();
//	s_sinManualAngles[75] = AngleFinder<75, Sin>()();
//	s_sinManualAngles[76] = AngleFinder<76, Sin>()();
//	s_sinManualAngles[77] = AngleFinder<77, Sin>()();
//	s_sinManualAngles[78] = AngleFinder<78, Sin>()();
//	s_sinManualAngles[79] = AngleFinder<79, Sin>()();
//	s_sinManualAngles[80] = AngleFinder<80, Sin>()();
//	s_sinManualAngles[81] = AngleFinder<81, Sin>()();
//	s_sinManualAngles[82] = AngleFinder<82, Sin>()();
//	s_sinManualAngles[83] = AngleFinder<83, Sin>()();
//	s_sinManualAngles[84] = AngleFinder<84, Sin>()();
//	s_sinManualAngles[85] = AngleFinder<85, Sin>()();
//	s_sinManualAngles[86] = AngleFinder<86, Sin>()();
//	s_sinManualAngles[87] = AngleFinder<87, Sin>()();
//	s_sinManualAngles[88] = AngleFinder<88, Sin>()();
//	s_sinManualAngles[89] = AngleFinder<89, Sin>()();
//	s_sinManualAngles[90] = AngleFinder<90, Sin>()();
//	s_sinManualAngles[91] = AngleFinder<91, Sin>()();
//	s_sinManualAngles[92] = AngleFinder<92, Sin>()();
//	s_sinManualAngles[93] = AngleFinder<93, Sin>()();
//	s_sinManualAngles[94] = AngleFinder<94, Sin>()();
//	s_sinManualAngles[95] = AngleFinder<95, Sin>()();
//	s_sinManualAngles[96] = AngleFinder<96, Sin>()();
//	s_sinManualAngles[97] = AngleFinder<97, Sin>()();
//	s_sinManualAngles[98] = AngleFinder<98, Sin>()();
//	s_sinManualAngles[99] = AngleFinder<99, Sin>()();
//	s_sinManualAngles[100] = AngleFinder<100, Sin>()();
//	s_sinManualAngles[101] = AngleFinder<101, Sin>()();
//	s_sinManualAngles[102] = AngleFinder<102, Sin>()();
//	s_sinManualAngles[103] = AngleFinder<103, Sin>()();
//	s_sinManualAngles[104] = AngleFinder<104, Sin>()();
//	s_sinManualAngles[105] = AngleFinder<105, Sin>()();
//	s_sinManualAngles[106] = AngleFinder<106, Sin>()();
//	s_sinManualAngles[107] = AngleFinder<107, Sin>()();
//	s_sinManualAngles[108] = AngleFinder<108, Sin>()();
//	s_sinManualAngles[109] = AngleFinder<109, Sin>()();
//	s_sinManualAngles[110] = AngleFinder<110, Sin>()();
//	s_sinManualAngles[111] = AngleFinder<111, Sin>()();
//	s_sinManualAngles[112] = AngleFinder<112, Sin>()();
//	s_sinManualAngles[113] = AngleFinder<113, Sin>()();
//	s_sinManualAngles[114] = AngleFinder<114, Sin>()();
//	s_sinManualAngles[115] = AngleFinder<115, Sin>()();
//	s_sinManualAngles[116] = AngleFinder<116, Sin>()();
//	s_sinManualAngles[117] = AngleFinder<117, Sin>()();
//	s_sinManualAngles[118] = AngleFinder<118, Sin>()();
//	s_sinManualAngles[119] = AngleFinder<119, Sin>()();
//	s_sinManualAngles[120] = AngleFinder<120, Sin>()();
//	s_sinManualAngles[121] = AngleFinder<121, Sin>()();
//	s_sinManualAngles[122] = AngleFinder<122, Sin>()();
//	s_sinManualAngles[123] = AngleFinder<123, Sin>()();
//	s_sinManualAngles[124] = AngleFinder<124, Sin>()();
//	s_sinManualAngles[125] = AngleFinder<125, Sin>()();
//	s_sinManualAngles[126] = AngleFinder<126, Sin>()();
//	s_sinManualAngles[127] = AngleFinder<127, Sin>()();
//	s_sinManualAngles[128] = AngleFinder<128, Sin>()();
//	s_sinManualAngles[129] = AngleFinder<129, Sin>()();
//	s_sinManualAngles[130] = AngleFinder<130, Sin>()();
//	s_sinManualAngles[131] = AngleFinder<131, Sin>()();
//	s_sinManualAngles[132] = AngleFinder<132, Sin>()();
//	s_sinManualAngles[133] = AngleFinder<133, Sin>()();
//	s_sinManualAngles[134] = AngleFinder<134, Sin>()();
//	s_sinManualAngles[135] = AngleFinder<135, Sin>()();
//	s_sinManualAngles[136] = AngleFinder<136, Sin>()();
//	s_sinManualAngles[137] = AngleFinder<137, Sin>()();
//	s_sinManualAngles[138] = AngleFinder<138, Sin>()();
//	s_sinManualAngles[139] = AngleFinder<139, Sin>()();
//	s_sinManualAngles[140] = AngleFinder<140, Sin>()();
//	s_sinManualAngles[141] = AngleFinder<141, Sin>()();
//	s_sinManualAngles[142] = AngleFinder<142, Sin>()();
//	s_sinManualAngles[143] = AngleFinder<143, Sin>()();
//	s_sinManualAngles[144] = AngleFinder<144, Sin>()();
//	s_sinManualAngles[145] = AngleFinder<145, Sin>()();
//	s_sinManualAngles[146] = AngleFinder<146, Sin>()();
//	s_sinManualAngles[147] = AngleFinder<147, Sin>()();
//	s_sinManualAngles[148] = AngleFinder<148, Sin>()();
//	s_sinManualAngles[149] = AngleFinder<149, Sin>()();
//	s_sinManualAngles[150] = AngleFinder<150, Sin>()();
//	s_sinManualAngles[151] = AngleFinder<151, Sin>()();
//	s_sinManualAngles[152] = AngleFinder<152, Sin>()();
//	s_sinManualAngles[153] = AngleFinder<153, Sin>()();
//	s_sinManualAngles[154] = AngleFinder<154, Sin>()();
//	s_sinManualAngles[155] = AngleFinder<155, Sin>()();
//	s_sinManualAngles[156] = AngleFinder<156, Sin>()();
//	s_sinManualAngles[157] = AngleFinder<157, Sin>()();
//	s_sinManualAngles[158] = AngleFinder<158, Sin>()();
//	s_sinManualAngles[159] = AngleFinder<159, Sin>()();
//	s_sinManualAngles[160] = AngleFinder<160, Sin>()();
//	s_sinManualAngles[161] = AngleFinder<161, Sin>()();
//	s_sinManualAngles[162] = AngleFinder<162, Sin>()();
//	s_sinManualAngles[163] = AngleFinder<163, Sin>()();
//	s_sinManualAngles[164] = AngleFinder<164, Sin>()();
//	s_sinManualAngles[165] = AngleFinder<165, Sin>()();
//	s_sinManualAngles[166] = AngleFinder<166, Sin>()();
//	s_sinManualAngles[167] = AngleFinder<167, Sin>()();
//	s_sinManualAngles[168] = AngleFinder<168, Sin>()();
//	s_sinManualAngles[169] = AngleFinder<169, Sin>()();
//	s_sinManualAngles[170] = AngleFinder<170, Sin>()();
//	s_sinManualAngles[171] = AngleFinder<171, Sin>()();
//	s_sinManualAngles[172] = AngleFinder<172, Sin>()();
//	s_sinManualAngles[173] = AngleFinder<173, Sin>()();
//	s_sinManualAngles[174] = AngleFinder<174, Sin>()();
//	s_sinManualAngles[175] = AngleFinder<175, Sin>()();
//	s_sinManualAngles[176] = AngleFinder<176, Sin>()();
//	s_sinManualAngles[177] = AngleFinder<177, Sin>()();
//	s_sinManualAngles[178] = AngleFinder<178, Sin>()();
//	s_sinManualAngles[179] = AngleFinder<179, Sin>()();
//	s_sinManualAngles[180] = AngleFinder<180, Sin>()();
//	s_sinManualAngles[181] = AngleFinder<181, Sin>()();
//	s_sinManualAngles[182] = AngleFinder<182, Sin>()();
//	s_sinManualAngles[183] = AngleFinder<183, Sin>()();
//	s_sinManualAngles[184] = AngleFinder<184, Sin>()();
//	s_sinManualAngles[185] = AngleFinder<185, Sin>()();
//	s_sinManualAngles[186] = AngleFinder<186, Sin>()();
//	s_sinManualAngles[187] = AngleFinder<187, Sin>()();
//	s_sinManualAngles[188] = AngleFinder<188, Sin>()();
//	s_sinManualAngles[189] = AngleFinder<189, Sin>()();
//	s_sinManualAngles[190] = AngleFinder<190, Sin>()();
//	s_sinManualAngles[191] = AngleFinder<191, Sin>()();
//	s_sinManualAngles[192] = AngleFinder<192, Sin>()();
//	s_sinManualAngles[193] = AngleFinder<193, Sin>()();
//	s_sinManualAngles[194] = AngleFinder<194, Sin>()();
//	s_sinManualAngles[195] = AngleFinder<195, Sin>()();
//	s_sinManualAngles[196] = AngleFinder<196, Sin>()();
//	s_sinManualAngles[197] = AngleFinder<197, Sin>()();
//	s_sinManualAngles[198] = AngleFinder<198, Sin>()();
//	s_sinManualAngles[199] = AngleFinder<199, Sin>()();
//	s_sinManualAngles[200] = AngleFinder<200, Sin>()();
//	s_sinManualAngles[201] = AngleFinder<201, Sin>()();
//	s_sinManualAngles[202] = AngleFinder<202, Sin>()();
//	s_sinManualAngles[203] = AngleFinder<203, Sin>()();
//	s_sinManualAngles[204] = AngleFinder<204, Sin>()();
//	s_sinManualAngles[205] = AngleFinder<205, Sin>()();
//	s_sinManualAngles[206] = AngleFinder<206, Sin>()();
//	s_sinManualAngles[207] = AngleFinder<207, Sin>()();
//	s_sinManualAngles[208] = AngleFinder<208, Sin>()();
//	s_sinManualAngles[209] = AngleFinder<209, Sin>()();
//	s_sinManualAngles[210] = AngleFinder<210, Sin>()();
//	s_sinManualAngles[211] = AngleFinder<211, Sin>()();
//	s_sinManualAngles[212] = AngleFinder<212, Sin>()();
//	s_sinManualAngles[213] = AngleFinder<213, Sin>()();
//	s_sinManualAngles[214] = AngleFinder<214, Sin>()();
//	s_sinManualAngles[215] = AngleFinder<215, Sin>()();
//	s_sinManualAngles[216] = AngleFinder<216, Sin>()();
//	s_sinManualAngles[217] = AngleFinder<217, Sin>()();
//	s_sinManualAngles[218] = AngleFinder<218, Sin>()();
//	s_sinManualAngles[219] = AngleFinder<219, Sin>()();
//	s_sinManualAngles[220] = AngleFinder<220, Sin>()();
//	s_sinManualAngles[221] = AngleFinder<221, Sin>()();
//	s_sinManualAngles[222] = AngleFinder<222, Sin>()();
//	s_sinManualAngles[223] = AngleFinder<223, Sin>()();
//	s_sinManualAngles[224] = AngleFinder<224, Sin>()();
//	s_sinManualAngles[225] = AngleFinder<225, Sin>()();
//	s_sinManualAngles[226] = AngleFinder<226, Sin>()();
//	s_sinManualAngles[227] = AngleFinder<227, Sin>()();
//	s_sinManualAngles[228] = AngleFinder<228, Sin>()();
//	s_sinManualAngles[229] = AngleFinder<229, Sin>()();
//	s_sinManualAngles[230] = AngleFinder<230, Sin>()();
//	s_sinManualAngles[231] = AngleFinder<231, Sin>()();
//	s_sinManualAngles[232] = AngleFinder<232, Sin>()();
//	s_sinManualAngles[233] = AngleFinder<233, Sin>()();
//	s_sinManualAngles[234] = AngleFinder<234, Sin>()();
//	s_sinManualAngles[235] = AngleFinder<235, Sin>()();
//	s_sinManualAngles[236] = AngleFinder<236, Sin>()();
//	s_sinManualAngles[237] = AngleFinder<237, Sin>()();
//	s_sinManualAngles[238] = AngleFinder<238, Sin>()();
//	s_sinManualAngles[239] = AngleFinder<239, Sin>()();
//	s_sinManualAngles[240] = AngleFinder<240, Sin>()();
//	s_sinManualAngles[241] = AngleFinder<241, Sin>()();
//	s_sinManualAngles[242] = AngleFinder<242, Sin>()();
//	s_sinManualAngles[243] = AngleFinder<243, Sin>()();
//	s_sinManualAngles[244] = AngleFinder<244, Sin>()();
//	s_sinManualAngles[245] = AngleFinder<245, Sin>()();
//	s_sinManualAngles[246] = AngleFinder<246, Sin>()();
//	s_sinManualAngles[247] = AngleFinder<247, Sin>()();
//	s_sinManualAngles[248] = AngleFinder<248, Sin>()();
//	s_sinManualAngles[249] = AngleFinder<249, Sin>()();
//	s_sinManualAngles[250] = AngleFinder<250, Sin>()();
//	s_sinManualAngles[251] = AngleFinder<251, Sin>()();
//	s_sinManualAngles[252] = AngleFinder<252, Sin>()();
//	s_sinManualAngles[253] = AngleFinder<253, Sin>()();
//	s_sinManualAngles[254] = AngleFinder<254, Sin>()();
//	s_sinManualAngles[255] = AngleFinder<255, Sin>()();
//	s_sinManualAngles[256] = AngleFinder<256, Sin>()();
//	s_sinManualAngles[257] = AngleFinder<257, Sin>()();
//	s_sinManualAngles[258] = AngleFinder<258, Sin>()();
//	s_sinManualAngles[259] = AngleFinder<259, Sin>()();
//	s_sinManualAngles[260] = AngleFinder<260, Sin>()();
//	s_sinManualAngles[261] = AngleFinder<261, Sin>()();
//	s_sinManualAngles[262] = AngleFinder<262, Sin>()();
//	s_sinManualAngles[263] = AngleFinder<263, Sin>()();
//	s_sinManualAngles[264] = AngleFinder<264, Sin>()();
//	s_sinManualAngles[265] = AngleFinder<265, Sin>()();
//	s_sinManualAngles[266] = AngleFinder<266, Sin>()();
//	s_sinManualAngles[267] = AngleFinder<267, Sin>()();
//	s_sinManualAngles[268] = AngleFinder<268, Sin>()();
//	s_sinManualAngles[269] = AngleFinder<269, Sin>()();
//	s_sinManualAngles[270] = AngleFinder<270, Sin>()();
//	s_sinManualAngles[271] = AngleFinder<271, Sin>()();
//	s_sinManualAngles[272] = AngleFinder<272, Sin>()();
//	s_sinManualAngles[273] = AngleFinder<273, Sin>()();
//	s_sinManualAngles[274] = AngleFinder<274, Sin>()();
//	s_sinManualAngles[275] = AngleFinder<275, Sin>()();
//	s_sinManualAngles[276] = AngleFinder<276, Sin>()();
//	s_sinManualAngles[277] = AngleFinder<277, Sin>()();
//	s_sinManualAngles[278] = AngleFinder<278, Sin>()();
//	s_sinManualAngles[279] = AngleFinder<279, Sin>()();
//	s_sinManualAngles[280] = AngleFinder<280, Sin>()();
//	s_sinManualAngles[281] = AngleFinder<281, Sin>()();
//	s_sinManualAngles[282] = AngleFinder<282, Sin>()();
//	s_sinManualAngles[283] = AngleFinder<283, Sin>()();
//	s_sinManualAngles[284] = AngleFinder<284, Sin>()();
//	s_sinManualAngles[285] = AngleFinder<285, Sin>()();
//	s_sinManualAngles[286] = AngleFinder<286, Sin>()();
//	s_sinManualAngles[287] = AngleFinder<287, Sin>()();
//	s_sinManualAngles[288] = AngleFinder<288, Sin>()();
//	s_sinManualAngles[289] = AngleFinder<289, Sin>()();
//	s_sinManualAngles[290] = AngleFinder<290, Sin>()();
//	s_sinManualAngles[291] = AngleFinder<291, Sin>()();
//	s_sinManualAngles[292] = AngleFinder<292, Sin>()();
//	s_sinManualAngles[293] = AngleFinder<293, Sin>()();
//	s_sinManualAngles[294] = AngleFinder<294, Sin>()();
//	s_sinManualAngles[295] = AngleFinder<295, Sin>()();
//	s_sinManualAngles[296] = AngleFinder<296, Sin>()();
//	s_sinManualAngles[297] = AngleFinder<297, Sin>()();
//	s_sinManualAngles[298] = AngleFinder<298, Sin>()();
//	s_sinManualAngles[299] = AngleFinder<299, Sin>()();
//	s_sinManualAngles[300] = AngleFinder<300, Sin>()();
//	s_sinManualAngles[301] = AngleFinder<301, Sin>()();
//	s_sinManualAngles[302] = AngleFinder<302, Sin>()();
//	s_sinManualAngles[303] = AngleFinder<303, Sin>()();
//	s_sinManualAngles[304] = AngleFinder<304, Sin>()();
//	s_sinManualAngles[305] = AngleFinder<305, Sin>()();
//	s_sinManualAngles[306] = AngleFinder<306, Sin>()();
//	s_sinManualAngles[307] = AngleFinder<307, Sin>()();
//	s_sinManualAngles[308] = AngleFinder<308, Sin>()();
//	s_sinManualAngles[309] = AngleFinder<309, Sin>()();
//	s_sinManualAngles[310] = AngleFinder<310, Sin>()();
//	s_sinManualAngles[311] = AngleFinder<311, Sin>()();
//	s_sinManualAngles[312] = AngleFinder<312, Sin>()();
//	s_sinManualAngles[313] = AngleFinder<313, Sin>()();
//	s_sinManualAngles[314] = AngleFinder<314, Sin>()();
//	s_sinManualAngles[315] = AngleFinder<315, Sin>()();
//	s_sinManualAngles[316] = AngleFinder<316, Sin>()();
//	s_sinManualAngles[317] = AngleFinder<317, Sin>()();
//	s_sinManualAngles[318] = AngleFinder<318, Sin>()();
//	s_sinManualAngles[319] = AngleFinder<319, Sin>()();
//	s_sinManualAngles[320] = AngleFinder<320, Sin>()();
//	s_sinManualAngles[321] = AngleFinder<321, Sin>()();
//	s_sinManualAngles[322] = AngleFinder<322, Sin>()();
//	s_sinManualAngles[323] = AngleFinder<323, Sin>()();
//	s_sinManualAngles[324] = AngleFinder<324, Sin>()();
//	s_sinManualAngles[325] = AngleFinder<325, Sin>()();
//	s_sinManualAngles[326] = AngleFinder<326, Sin>()();
//	s_sinManualAngles[327] = AngleFinder<327, Sin>()();
//	s_sinManualAngles[328] = AngleFinder<328, Sin>()();
//	s_sinManualAngles[329] = AngleFinder<329, Sin>()();
//	s_sinManualAngles[330] = AngleFinder<330, Sin>()();
//	s_sinManualAngles[331] = AngleFinder<331, Sin>()();
//	s_sinManualAngles[332] = AngleFinder<332, Sin>()();
//	s_sinManualAngles[333] = AngleFinder<333, Sin>()();
//	s_sinManualAngles[334] = AngleFinder<334, Sin>()();
//	s_sinManualAngles[335] = AngleFinder<335, Sin>()();
//	s_sinManualAngles[336] = AngleFinder<336, Sin>()();
//	s_sinManualAngles[337] = AngleFinder<337, Sin>()();
//	s_sinManualAngles[338] = AngleFinder<338, Sin>()();
//	s_sinManualAngles[339] = AngleFinder<339, Sin>()();
//	s_sinManualAngles[340] = AngleFinder<340, Sin>()();
//	s_sinManualAngles[341] = AngleFinder<341, Sin>()();
//	s_sinManualAngles[342] = AngleFinder<342, Sin>()();
//	s_sinManualAngles[343] = AngleFinder<343, Sin>()();
//	s_sinManualAngles[344] = AngleFinder<344, Sin>()();
//	s_sinManualAngles[345] = AngleFinder<345, Sin>()();
//	s_sinManualAngles[346] = AngleFinder<346, Sin>()();
//	s_sinManualAngles[347] = AngleFinder<347, Sin>()();
//	s_sinManualAngles[348] = AngleFinder<348, Sin>()();
//	s_sinManualAngles[349] = AngleFinder<349, Sin>()();
//	s_sinManualAngles[350] = AngleFinder<350, Sin>()();
//	s_sinManualAngles[351] = AngleFinder<351, Sin>()();
//	s_sinManualAngles[352] = AngleFinder<352, Sin>()();
//	s_sinManualAngles[353] = AngleFinder<353, Sin>()();
//	s_sinManualAngles[354] = AngleFinder<354, Sin>()();
//	s_sinManualAngles[355] = AngleFinder<355, Sin>()();
//	s_sinManualAngles[356] = AngleFinder<356, Sin>()();
//	s_sinManualAngles[357] = AngleFinder<357, Sin>()();
//	s_sinManualAngles[358] = AngleFinder<358, Sin>()();
//	s_sinManualAngles[359] = AngleFinder<359, Sin>()();
//	s_sinManualAngles[360] = AngleFinder<360, Sin>()();
//}
