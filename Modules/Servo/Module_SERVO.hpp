#ifndef __MODULE_SERVO_HPP__
#define __MODULE_SERVO_HPP__
class Module_SERVO
{
	private:
		bool 	m_initialized;
		
		int		m_upper_boundary;
		int		m_lower_boundary;
		
		int		m_target;
		
		MAESTRO	m_servo_hardware_connection;
	
	public:
		Module_SERVO(int upper_limit, int lower_limit);
		
		bool init();
		
		void run();
		void set_target(int limit);
		
		
};
#endif//__MODULE_SERVO_HPP__
