#include "pch.h"
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../autoTransport/Container.h"
#include "../autoTransport/Bus.h"
#include "../autoTransport/Transport.h"
#include "../autoTransport/Truck.h"
#include "../autoTransport/Car.h"

#include "../autoTransport/Container_Constr.cpp"
#include "../autoTransport/Container_In.cpp"
#include "../autoTransport/Container_Out.cpp"
#include "../autoTransport/Bus_In.cpp"
#include "../autoTransport/Bus_Out.cpp"
#include "../autoTransport/Transport_Compare.cpp"
#include "../autoTransport/Transport_In.cpp"
#include "../autoTransport/Transport_Out.cpp"
#include "../autoTransport/Truck_In.cpp"
#include "../autoTransport/Truck_Out.cpp"
#include "../autoTransport/Car_In.cpp"
#include "../autoTransport/Car_Out.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(WPRatioT)
		{
			Truck transport;
			transport.mData = 25;
			transport.tPower = 25;
			float actual = WPRatio(&transport);
			float expected = (float)(transport.mData) / (float)transport.tPower;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(WPRatioB)
		{
			Bus transport;
			transport.mData = 25;
			transport.tPower = 25;
			float actual = WPRatio(&transport);
			float expected = (float)(transport.mData *75) / (float)transport.tPower;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(WPRatioC)
		{
			Car transport;
			//transport.mData = 25;
			transport.tPower = 25;
			float actual = WPRatio(&transport);
			float expected = (float)(75 * 4 ) / (float)transport.tPower;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestCompareM)
		{
			Bus* transport_new = new Bus;
			Car* transport_old = new Car;
			transport_new->mKey = type::BUS;
			transport_new->mData = 1;
			transport_new->tPower = 25;
			transport_old->mKey = type::CAR;
			transport_old->mData = 1;
			transport_old->tPower = 25;
			//75*1/25 < 75*4/25
			bool actual = Compare((Transport*)transport_new, (Transport*)transport_old);
			bool expected = true;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(BusInputM)
		{
			ifstream fin("D:/GitHub/autoTransport/UnitTest/In_Bus_Test.txt");

			Bus* actual = InBus(fin);
			Bus* expected = new Bus;

			expected->mKey = type::BUS;
			expected->tPower = 9;
			expected->mData = 7;
			expected->fuelConsumption = 2;
			
			Assert::AreEqual((int)expected->mKey, (int)actual->mKey);
			Assert::AreEqual(expected->tPower, actual->tPower);
			Assert::AreEqual(expected->mData, actual->mData);
			Assert::AreEqual((float)expected->fuelConsumption, (float)actual->fuelConsumption);
		}

		TEST_METHOD(CarOutput)
		{
			ofstream fout("D:/GitHub/autoTransport/UnitTest/Out_Car_Test_Act.txt");
			Car* act = new Car;

			act->tPower = 5;
			act->mData = 100;
			act->mKey = type::CAR;
			act->fuelConsumption = 12;

			Out(act, fout);

			ifstream fin_act("D:/GitHub/autoTransport/UnitTest/Out_Car_Test_Act.txt");
			ifstream fin_exp("D:/GitHub/autoTransport/UnitTest/Out_Car_Test_Exp.txt");

			string expected, actual;
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(ContainerStream)
		{
			ifstream fin("D:/GitHub/autoTransport/UnitTest/ContainerOutputIn.txt");
			ofstream fout("D:/GitHub/autoTransport/UnitTest/ContainerOutput.txt");
			Container c;
			Init(c);
			In(c, fin);
			Out(c, fout);
			fout.close();
			ifstream fin_exp("D:/GitHub/autoTransport/UnitTest/ContainerOutputExp.txt");
			ifstream fin_act("D:/GitHub/autoTransport/UnitTest/ContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(SortContainer)
		{
			ifstream fin("D:/GitHub/autoTransport/UnitTest/ContainerOutputIn.txt");
			ofstream fout("D:/GitHub/autoTransport/UnitTest/ContainerOutput.txt");
			Container* c = new Container;
			Init(*c);
			In(*c, fin);
			Sort(c);
			Out(*c, fout);
			fout.close();
			ifstream fin_exp("D:/GitHub/autoTransport/UnitTest/SortContainerExp.txt");
			ifstream fin_act("D:/GitHub/autoTransport/UnitTest/ContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(OnlyBus)
		{
			ifstream fin("D:\\GitHub\\autoTransport\\UnitTest\\ContainerOutputIn.txt");
			ofstream fout("D:\\GitHub\\autoTransport\\UnitTest\\ContainerOutput.txt");
			Container c;
			Init(c);
			In(c, fin);
			Out(c, fout);
			fout.close();
			ifstream fin_exp("D:\\GitHub\\autoTransport\\UnitTest\\OnlyBusExp.txt");
			ifstream fin_act("D:\\GitHub\\autoTransport\\UnitTest\\ContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual);
		}
	};
}
