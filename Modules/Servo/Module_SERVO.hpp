#ifndef __MODULE_SERVO_HPP__
#define __MODULE_SERVO_HPP__
class Module_SERVO
{
	private:
		bool 	m_initialized;
		
		int		m_upper_bound;
		int		m_lower_bound;
	
	public:
		Module_SERVO();
		
		bool init();
};
#endif//__MODULE_SERVO_HPP__
