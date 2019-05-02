#ifndef __MA3_HPP__
#define __MA3_HPP__
class MA3
{
    private:
      bool m_initialized;

      WIND_DATA m_reading;

    public:
        MA3();

        bool init();
};
#endif//__MA3_HPP__
