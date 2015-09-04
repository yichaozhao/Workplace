#include "Dot.h"

namespace Geom
{

std::string Dot::toString() const
{
	{ return "x = " + std::to_string(m_x) + " y = " + std::to_string(m_y) + " z = " + std::to_string(m_z); }
}

}

