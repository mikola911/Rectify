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
   * ����o� ����������� ������� �� ������������ ��� ������ �������� � ���������� ���������.
   */
#define preheatingDeltaTempJump 20

  /**
   * ����������� ��� ������� �� �������, ��� ����� � ������.
   */
#define preheatingTempErrorMax 100
   /**
	* ����������� ��� ������� �� �������, ��� ����� � ������.
	*/
#define preheatingTempErrorMin 0


	 /**
	  * �������� ������� ��������� ������ ����������� ������ �����������.
	  */
#define preheatingDeltaTimeForDeltaTemp 1000

	  //������
	  /**
	   * ����������� ��� ������� ������� ������� ����� ������� ����������.
	   */
#define heatMaxTem 70

	   /**
		* ������ ����������� ���������� ��� ������ � ���������� ����� ������� �����.
		*/
#define heatDeltaTemp 0.5

		/**
		 * ����� � ������� �������� ����������� �������� ������ ���������� ����������.
		 */
#define heatConstTempTime 60*1000*300
		 /**
		  * ����������� ��� ������� �� �������, ��� ����� � ������.
		  */
#define heatTempErrorMax 100
		  /**
		   * ����������� ��� ������� �� �������, ��� ����� � ������.
		   */
#define heatTempErrorMin 0

		   //����� �����

		   /**
			* ���� �������� ����������� ��� ������ �����.
			*/
#define headSelectionServoAngle 170


			//��������������� �����

			/**
			 * �������������� ����� [��.]
			 */
#define technologicalBreakTimeout 60L*1000L*1L// #TODO
			 /**
			  * ���� �������� ����������� �� ����� ��������������� �����.
			  */
#define technologicalBreakServoPosition 180


			  //����� ������

			  /**
			   * ����� �������� ������������ ��� ������� ����� ������ ���������
			   */
#define nodeSelectionCloseAngle 180

			   /**
				* ����� �������� ������������ ��� ������� ����� ������ ����.
				*/
#define nodeSelectionOpenAngle 150
				/**
				 * ����� ����������� �� ������� ����� ��������� ��� ������ �����.
				 */
#define nodeSelectionDeltaTemp 0.2
				 /**
				 * ������������ ����� ������� ������ �������� ������� � ������� �������� ����������� �� ������.
				 */
#define ladgeTempAfterClosingTimeMax 1000*20