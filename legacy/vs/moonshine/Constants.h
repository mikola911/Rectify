#pragma once
//�������������

/**
 * ��������� ���� ������������.
 */
#define startServoAngle  180

 //����������

 /**
  * ����������� ��� ������� �� �������, ��� ���������� ��������
  */
#define preheatingTempJump 55
  /**
   * ������ ����������� ������� �� ������������ ��� ������ �������� � ���������� ���������.
   */
#define preheatingDeltaTempJump 20

  /**
   * ����������� ��� ������� �� �������, ��� ����� � ������.
   */
#define preheatingTempErrorMax 220
   /**
	* ����������� ��� ������� �� �������, ��� ����� � ������.
	*/
#define preheatingTempErrorMin -20


	 /**
	  * �������� ������� ��������� ������ ����������� ������ �����������.
	  */
#define preheatingDeltaTimeForDeltaTemp 10000

	  //������
	  /**
	   * ����������� ��� ������� ������� ������� ����� ������� ����������.
	   */
#define heatMaxTem 70

	   /**
		* ������ ����������� ���������� ��� ������ � ���������� ����� ������� �����.
		* !!!�������� ���� ������ � INT!!!!
		*/
#define heatDeltaTemp 1

		/**
		 * ����� � ������� �������� ����������� �������� ������ ���������� ����������.
		 */
#define heatConstTempTime 60*1000*300
		 /**
		  * ����������� ��� ������� �� �������, ��� ����� � ������.
		  */
#define heatTempErrorMax 220
		  /**
		   * ����������� ��� ������� �� �������, ��� ����� � ������.
		   */
#define heatTempErrorMin -20

		   //����� �����

		   /**
			* ���� �������� ����������� ��� ������ �����.
			*/
#define headSelectionServoAngle 10


			//��������������� �����

			/**
			 * �������������� ����� [��.]
			 */
#define technologicalBreakTimeout 60L*1000L*1L// #TODO
			 /**
			  * ���� �������� ����������� �� ����� ��������������� �����.
			  */
#define technologicalBreakServoPosition 15


			  //����� ������

			  /**
			   * ����� �������� ������������ ��� ������� ����� ������ ���������
			   */
#define nodeSelectionCloseAngle 0

			   /**
				* ����� �������� ������������ ��� ������� ����� ������ ����.
				*/
#define nodeSelectionOpenAngle 230
				/**
				 * ����� ����������� �� ������� ����� ��������� ��� ������ �����.
				 */
#define nodeSelectionDeltaTemp 0.5
				 /**
				 * ������������ ����� ������� ������ �������� ������� � ������� �������� ����������� �� ������.
				 */
#define ladgeTempAfterClosingTimeMax 1000*20