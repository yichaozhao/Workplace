#include "gtest\gtest.h"
#include "Geometries.h"
#include "Octree.h"
#include <vector>

TEST(OctreeTest, CreateOctree)
{
	Geom::Dot a(0.17176, 0.73716, 0.42617); Geom::Dot A(0.79643, 0.77193, 0.22376);
	Geom::Dot b(0.83991, 0.70922, 0.03450); Geom::Dot B(0.39415, 0.53672, 0.29356);
	Geom::Dot c(0.36830, 0.45206, 0.18853); Geom::Dot C(0.72783, 0.94871, 0.42943);
	Geom::Dot d(0.80773, 0.39966, 0.46594); Geom::Dot D(0.18622, 0.69044, 0.68756);
	Geom::Dot e(0.13608, 0.71868, 0.68363); Geom::Dot E(0.14575, 0.60599, 0.29092);
	Geom::Dot f(0.02506, 0.58755, 0.60577); Geom::Dot F(0.90322, 0.78594, 0.33636);
	Geom::Dot g(0.92342, 0.79894, 0.18964); Geom::Dot G(0.49062, 0.86999, 0.53361);
	Geom::Dot h(0.49834, 0.12556, 0.03967); Geom::Dot H(0.33805, 0.47435, 0.16622);
	Geom::Dot i(0.54978, 0.83445, 0.78664); Geom::Dot I(0.75645, 0.24347, 0.24034);
	Geom::Dot j(0.77786, 0.50339, 0.64151); Geom::Dot J(0.96056, 0.63395, 0.75487);
	Geom::Dot k(0.62790, 0.00785, 0.49251); Geom::Dot K(0.09378, 0.41333, 0.08814);
	Geom::Dot l(0.38091, 0.22266, 0.85261); Geom::Dot L(0.47705, 0.47977, 0.87603);
	Geom::Dot m(0.33814, 0.74295, 0.39742); Geom::Dot M(0.35417, 0.55971, 0.47861);
	Geom::Dot n(0.40231, 0.22734, 0.98551); Geom::Dot N(0.89867, 0.77211, 0.99088);
	Geom::Dot o(0.64737, 0.61498, 0.35685); Geom::Dot O(0.42216, 0.04916, 0.06775);
	Geom::Dot p(0.41085, 0.24719, 0.81326); Geom::Dot P(0.93991, 0.36831, 0.63504);
	Geom::Dot q(0.73159, 0.11901, 0.53591); Geom::Dot Q(0.10460, 0.80190, 0.33997);
	Geom::Dot r(0.43731, 0.60818, 0.22079); Geom::Dot R(0.34186, 0.12259, 0.54386);
	Geom::Dot s(0.45537, 0.31767, 0.83409); Geom::Dot S(0.17601, 0.97741, 0.92136);
	Geom::Dot t(0.07009, 0.84927, 0.67810); Geom::Dot T(0.37433, 0.60904, 0.88248);
	Geom::Dot u(0.55007, 0.83002, 0.45343); Geom::Dot U(0.29474, 0.15504, 0.65971);
	Geom::Dot v(0.27188, 0.52490, 0.57604); Geom::Dot V(0.67172, 0.53740, 0.82316);
	Geom::Dot w(0.14561, 0.19545, 0.09650); Geom::Dot W(0.62250, 0.68892, 0.95424);
	Geom::Dot x(0.03081, 0.36213, 0.34388); Geom::Dot X(0.11814, 0.98555, 0.69168);
	Geom::Dot y(0.99839, 0.63111, 0.87081); Geom::Dot Y(0.17432, 0.86212, 0.36284);
	Geom::Dot z(0.51463, 0.71624, 0.07241); Geom::Dot Z(0.04787, 0.83070, 0.51791);

	Octree* pOctree;
	std::vector<Geom::Object*> objectVector = {
		&a, &b, &c, &d, &e, &f, &g,
		&h, &i, &j, &k, &l, &m, &n,
		&o, &p, &q, &r, &s, &t, 
		&u, &v, &w, &x, &y, &z,
		&A, &B, &C, &D, &E, &F, &G,
		&H, &I, &J, &K, &L, &M, &N,
		&O, &P, &Q, &R, &S, &T, 
		&U, &V, &W, &X, &Y, &Z}; 

	std::vector<Geom::Object*> objectVector2 = { &a, &b, &c, &d, &e, &f, &g, &h, &i };
	Octree::CreateOctree(pOctree, objectVector);
	EXPECT_EQ(52, pOctree->DebugCountObject());

	EXPECT_TRUE(pOctree->DebugVolumeChecksum());
	EXPECT_FALSE(pOctree->IsLeaf());
	EXPECT_TRUE(pOctree->GetChildOctree(0)->IsLeaf());

	delete pOctree;
}