//класс описывает мат модель робота
class RobotinoPiModel
{
public:

    RobotinoPiModel();
    /*
    *   Calculate omegaA in PRM
    */
    void setOmegaA(float velocity, float alpha);

    /*
    *   Calculate omegaB in PRM
    */
    void setOmegaB(float velocity, float alpha);


    /*
    *   Calculate omegaC in PRM
    */
    void setOmegaC(float velocity, float alpha);


    /*
     *  Calculate angle from x and y
    */
    double calcCoordinate(double x, double y);

        /*
    *   convert value to value (float to uint8_t) For speed -> PWM
    *   float map(float inX, float in_min, float in_max, float out_min, float out_max)
    */
    float convertValueToSpeedEngineA();

    /*
    *   convert value to value (float to uint8_t) For speed -> PWM
    *   float map(float inX, float in_min, float in_max, float out_min, float out_max)
    */
    float convertValueToSpeedEngineB();

    /*
    *   convert value to value (float to uint8_t) For speed -> PWM
    *   float map(float inX, float in_min, float in_max, float out_min, float out_max)
    */
    float convertValueToSpeedEngineC();

    /*
    *   test direction of moving (H-bridge) if true -> to left, else to right
    */
    bool whichDirectonHbridgeA();

    /*
    *   test direction of moving (H-bridge) if true -> to left, else to right
    */
    bool whichDirectonHbridgeB();

    /*
    *   test direction of moving (H-bridge) if true -> to left, else to right
    */
    bool whichDirectonHbridgeC();


private:
    float m_omegaA;
    float m_omegaB;
    float m_omegaC;

    float m_velocity;
    float m_coordinate;

    float  m_wheelASpeed;
    float  m_wheelBSpeed;
    float  m_wheelCSpeed;

};
