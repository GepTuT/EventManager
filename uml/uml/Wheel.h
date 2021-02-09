#pragma once
#include <iostream>




class Wheel {
public:
	class TireTube;
	class TireWheel;
	class TireDisk;

	Wheel() : m_tiretube(), m_tirewheel(),m_tiredisk() {
		std::cout << "Wheel Created\n";
	};

	class TireTube {
		std::string TireTubeName;
		double Size;
		double Durability;
	public:

		TireTube() { std::cout << "TireTube Created\n"; }
		std::string GetName() { return TireTubeName; }
		double GetSize() { return Size; }
		double ChangeTireTube() { Durability = 100.0; }
		double GetDurability() { return Durability; }
	};

	class TireWheel {
		std::string TireWheelName;
		double Size;
		double Durability;
	public:
		TireWheel() { std::cout << "TireWheel Created\n"; }
		std::string GetName() { return TireWheelName; }
		double GetDurability() { return Durability; }
		double ChangeTireWheel() { Durability = 100.0; }
		double GetSize() { return Size; }
	};

	class TireDisk {
		std::string DiskName;
		double Size;
		double Durability;
	public:

		TireDisk() { std::cout << "TireDisk Created\n"; }
		std::string GetName() { return DiskName; }
		double ChangeTireDisk() { Durability = 100.0; }
		double GetSize() { return Size; }
		double GetDurability() { return Durability; }
	};
	double ChangeTireDiskDurability() { m_tiredisk.ChangeTireDisk(); }

	double GetTireDiskDurability() { return m_tiredisk.GetDurability(); }

	double ChangeTireTubeDurability() { m_tiretube.ChangeTireTube(); }

	double GetTireTubeDurability() { return m_tiretube.GetDurability(); }

	double ChangeTireWheelDurability() { m_tirewheel.ChangeTireWheel(); }

	double GetTireWheelDurability() { return m_tirewheel.GetDurability(); }
private:
	TireTube m_tiretube;
	TireWheel m_tirewheel;
	TireDisk m_tiredisk;
	double m_Pressure;
};