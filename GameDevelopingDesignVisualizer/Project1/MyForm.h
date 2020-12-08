#pragma once
#include "DevelopData.h"
#include <msclr\marshal_cppstd.h>
#include <time.h>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// MyForm 摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			waitWhiteBoard->BringToFront();
			waitWhiteBoard->BringToFront();
			waitLabel->Hide();
			loadDataButton->BringToFront();
			startVisualizeButton->Hide();
			showPRSButton->Hide();
			showQDButton->Hide();
			showDCButton->Hide();
			panel->Hide();
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: System::Windows::Forms::Button^  loadDataButton;


	protected:


	private:
	private: System::Diagnostics::EventLog^  eventLog1;
	private: System::DirectoryServices::DirectorySearcher^  directorySearcher1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  taskList;

	private: System::DirectoryServices::DirectoryEntry^  directoryEntry1;





	private: System::Windows::Forms::OpenFileDialog^  findDataFile;

	private: System::Windows::Forms::PictureBox^  waitWhiteBoard;
	private: System::Windows::Forms::Label^  waitLabel;
	protected: System::Windows::Forms::Label^  loadStatus;
	protected: System::Windows::Forms::Button^  startVisualizeButton;
	private: System::Windows::Forms::Label^  label_selectedId;
	protected:

	protected:



	private: System::Windows::Forms::Panel^  panel;


	private: System::Windows::Forms::DataVisualization::Charting::Chart^  remainProblemChart;

	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  quitDistribution;
	private: System::Windows::Forms::Label^  label1;
	protected: System::Windows::Forms::Button^  showDCButton;
	private:
	protected: System::Windows::Forms::Button^  showQDButton;
	protected: System::Windows::Forms::Button^  showPRSButton;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  difficultyCurve;
	private: System::Windows::Forms::Label^  totalPlayerCount;

	protected:





	private:



	public:
	protected:

	protected:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->loadDataButton = (gcnew System::Windows::Forms::Button());
			this->eventLog1 = (gcnew System::Diagnostics::EventLog());
			this->directorySearcher1 = (gcnew System::DirectoryServices::DirectorySearcher());
			this->directoryEntry1 = (gcnew System::DirectoryServices::DirectoryEntry());
			this->taskList = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->findDataFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->waitWhiteBoard = (gcnew System::Windows::Forms::PictureBox());
			this->waitLabel = (gcnew System::Windows::Forms::Label());
			this->loadStatus = (gcnew System::Windows::Forms::Label());
			this->startVisualizeButton = (gcnew System::Windows::Forms::Button());
			this->label_selectedId = (gcnew System::Windows::Forms::Label());
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->difficultyCurve = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->remainProblemChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->quitDistribution = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->showPRSButton = (gcnew System::Windows::Forms::Button());
			this->showQDButton = (gcnew System::Windows::Forms::Button());
			this->showDCButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->totalPlayerCount = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->waitWhiteBoard))->BeginInit();
			this->panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->difficultyCurve))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->remainProblemChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quitDistribution))->BeginInit();
			this->SuspendLayout();
			// 
			// loadDataButton
			// 
			this->loadDataButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadDataButton->Location = System::Drawing::Point(711, 616);
			this->loadDataButton->Name = L"loadDataButton";
			this->loadDataButton->Size = System::Drawing::Size(230, 73);
			this->loadDataButton->TabIndex = 0;
			this->loadDataButton->Text = L"Load Data";
			this->loadDataButton->UseVisualStyleBackColor = true;
			this->loadDataButton->Click += gcnew System::EventHandler(this, &MyForm::LoadData);
			// 
			// eventLog1
			// 
			this->eventLog1->SynchronizingObject = this;
			// 
			// directorySearcher1
			// 
			this->directorySearcher1->ClientTimeout = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerPageTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			// 
			// taskList
			// 
			this->taskList->FormattingEnabled = true;
			this->taskList->ItemHeight = 12;
			this->taskList->Location = System::Drawing::Point(795, 71);
			this->taskList->Name = L"taskList";
			this->taskList->Size = System::Drawing::Size(146, 436);
			this->taskList->TabIndex = 2;
			this->taskList->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(804, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 21);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Task List";
			// 
			// findDataFile
			// 
			this->findDataFile->FileName = L"findDataFile";
			this->findDataFile->InitialDirectory = L"C:\\\\";
			// 
			// waitWhiteBoard
			// 
			this->waitWhiteBoard->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->waitWhiteBoard->Location = System::Drawing::Point(-1, 0);
			this->waitWhiteBoard->Name = L"waitWhiteBoard";
			this->waitWhiteBoard->Size = System::Drawing::Size(984, 701);
			this->waitWhiteBoard->TabIndex = 8;
			this->waitWhiteBoard->TabStop = false;
			// 
			// waitLabel
			// 
			this->waitLabel->AutoSize = true;
			this->waitLabel->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->waitLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->waitLabel->Location = System::Drawing::Point(327, 314);
			this->waitLabel->Name = L"waitLabel";
			this->waitLabel->Size = System::Drawing::Size(332, 62);
			this->waitLabel->TabIndex = 9;
			this->waitLabel->Text = L"Please wait ...";
			// 
			// loadStatus
			// 
			this->loadStatus->AutoSize = true;
			this->loadStatus->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->loadStatus->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadStatus->Location = System::Drawing::Point(12, 671);
			this->loadStatus->Name = L"loadStatus";
			this->loadStatus->Size = System::Drawing::Size(225, 21);
			this->loadStatus->TabIndex = 10;
			this->loadStatus->Text = L"none (please load a .gld file)";
			this->loadStatus->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// startVisualizeButton
			// 
			this->startVisualizeButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startVisualizeButton->Location = System::Drawing::Point(711, 523);
			this->startVisualizeButton->Name = L"startVisualizeButton";
			this->startVisualizeButton->Size = System::Drawing::Size(230, 81);
			this->startVisualizeButton->TabIndex = 11;
			this->startVisualizeButton->Text = L"Start Visualization";
			this->startVisualizeButton->UseVisualStyleBackColor = true;
			this->startVisualizeButton->Click += gcnew System::EventHandler(this, &MyForm::startVisualizeButton_Click);
			// 
			// label_selectedId
			// 
			this->label_selectedId->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_selectedId->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label_selectedId->Enabled = false;
			this->label_selectedId->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_selectedId->Location = System::Drawing::Point(802, 478);
			this->label_selectedId->Name = L"label_selectedId";
			this->label_selectedId->Size = System::Drawing::Size(133, 21);
			this->label_selectedId->TabIndex = 16;
			this->label_selectedId->Text = L"Selected Task Id";
			this->label_selectedId->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel
			// 
			this->panel->Controls->Add(this->remainProblemChart);
			this->panel->Controls->Add(this->quitDistribution);
			this->panel->Controls->Add(this->difficultyCurve);
			this->panel->Location = System::Drawing::Point(27, 12);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(751, 495);
			this->panel->TabIndex = 17;
			// 
			// difficultyCurve
			// 
			this->difficultyCurve->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
			chartArea3->AxisX->IsMarginVisible = false;
			chartArea3->AxisX2->IsMarginVisible = false;
			chartArea3->AxisY->IsMarginVisible = false;
			chartArea3->AxisY2->IsMarginVisible = false;
			chartArea3->Name = L"RemainProblem";
			this->difficultyCurve->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->difficultyCurve->Legends->Add(legend3);
			this->difficultyCurve->Location = System::Drawing::Point(0, 0);
			this->difficultyCurve->Name = L"difficultyCurve";
			series6->BorderWidth = 7;
			series6->ChartArea = L"RemainProblem";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bubble;
			series6->Color = System::Drawing::Color::DodgerBlue;
			series6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series6->Legend = L"Legend1";
			series6->MarkerColor = System::Drawing::Color::DodgerBlue;
			series6->Name = L"passRatio";
			series6->YValuesPerPoint = 2;
			series7->BorderWidth = 5;
			series7->ChartArea = L"RemainProblem";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series7->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series7->Legend = L"Legend1";
			series7->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series7->Name = L"remainNumber";
			series7->YAxisType = System::Windows::Forms::DataVisualization::Charting::AxisType::Secondary;
			series8->ChartArea = L"RemainProblem";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bubble;
			series8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series8->CustomProperties = L"IsXAxisQuantitative=True, BubbleMinSize=1, BubbleScaleMax=150, EmptyPointValue=Ze"
				L"ro, LabelStyle=Center, BubbleMaxSize=100";
			series8->Legend = L"Legend1";
			series8->Name = L"deadDistribution";
			series8->YAxisType = System::Windows::Forms::DataVisualization::Charting::AxisType::Secondary;
			series8->YValuesPerPoint = 2;
			this->difficultyCurve->Series->Add(series6);
			this->difficultyCurve->Series->Add(series7);
			this->difficultyCurve->Series->Add(series8);
			this->difficultyCurve->Size = System::Drawing::Size(751, 495);
			this->difficultyCurve->TabIndex = 21;
			this->difficultyCurve->Text = L"remainProblem";
			title3->Alignment = System::Drawing::ContentAlignment::TopLeft;
			title3->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::NotSet;
			title3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title3->Name = L"dfficultyCurve";
			title3->Text = L"Developing Bubble Distribution (for examming Learning Curve) ";
			this->difficultyCurve->Titles->Add(title3);
			// 
			// remainProblemChart
			// 
			this->remainProblemChart->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
			chartArea1->AxisX->IsMarginVisible = false;
			chartArea1->AxisX2->IsMarginVisible = false;
			chartArea1->AxisY->IsMarginVisible = false;
			chartArea1->AxisY2->IsMarginVisible = false;
			chartArea1->Name = L"RemainProblem";
			this->remainProblemChart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->remainProblemChart->Legends->Add(legend1);
			this->remainProblemChart->Location = System::Drawing::Point(0, 0);
			this->remainProblemChart->Name = L"remainProblemChart";
			series1->BorderWidth = 7;
			series1->ChartArea = L"RemainProblem";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::SplineArea;
			series1->Color = System::Drawing::Color::DodgerBlue;
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series1->Legend = L"Legend1";
			series1->MarkerColor = System::Drawing::Color::DodgerBlue;
			series1->Name = L"RemainNumber";
			series2->ChartArea = L"RemainProblem";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::SplineArea;
			series2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series2->Legend = L"Legend1";
			series2->MarkerColor = System::Drawing::Color::Tomato;
			series2->Name = L"QuitNumber";
			series3->BorderWidth = 7;
			series3->ChartArea = L"RemainProblem";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			series3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series3->Legend = L"Legend1";
			series3->MarkerBorderColor = System::Drawing::Color::LimeGreen;
			series3->MarkerBorderWidth = 7;
			series3->Name = L"RemainingRatio";
			series3->YAxisType = System::Windows::Forms::DataVisualization::Charting::AxisType::Secondary;
			series3->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series4->BorderWidth = 7;
			series4->ChartArea = L"RemainProblem";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series4->Legend = L"Legend1";
			series4->MarkerBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series4->MarkerBorderWidth = 7;
			series4->Name = L"QuittingRatio";
			series4->YAxisType = System::Windows::Forms::DataVisualization::Charting::AxisType::Secondary;
			series4->YValuesPerPoint = 2;
			series4->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->remainProblemChart->Series->Add(series1);
			this->remainProblemChart->Series->Add(series2);
			this->remainProblemChart->Series->Add(series3);
			this->remainProblemChart->Series->Add(series4);
			this->remainProblemChart->Size = System::Drawing::Size(751, 495);
			this->remainProblemChart->TabIndex = 19;
			this->remainProblemChart->Text = L"remainProblem";
			title1->Alignment = System::Drawing::ContentAlignment::TopLeft;
			title1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title1->Name = L"PlayerRemainingStatus";
			title1->Text = L"Player Remaining Status";
			this->remainProblemChart->Titles->Add(title1);
			this->remainProblemChart->Click += gcnew System::EventHandler(this, &MyForm::remainProblemChart_Click);
			// 
			// quitDistribution
			// 
			this->quitDistribution->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
			chartArea2->AxisX->IsMarginVisible = false;
			chartArea2->AxisX2->IsMarginVisible = false;
			chartArea2->AxisY->IsMarginVisible = false;
			chartArea2->AxisY2->IsMarginVisible = false;
			chartArea2->Name = L"RemainProblem";
			this->quitDistribution->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->quitDistribution->Legends->Add(legend2);
			this->quitDistribution->Location = System::Drawing::Point(0, 0);
			this->quitDistribution->Name = L"quitDistribution";
			series5->ChartArea = L"RemainProblem";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series5->CustomProperties = L"PieLineColor=255\\, 128\\, 128, CollectedSliceExploded=True, MinimumRelativePieSize"
				L"=15, PieLabelStyle=Outside, PieStartAngle=30";
			series5->Label = L"#VAL{P}  #VALX";
			series5->LabelBackColor = System::Drawing::Color::Black;
			series5->LabelBorderColor = System::Drawing::Color::Tomato;
			series5->LabelBorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::NotSet;
			series5->LabelForeColor = System::Drawing::Color::White;
			series5->Legend = L"Legend1";
			series5->Name = L"QuittingRatio";
			series5->SmartLabelStyle->AllowOutsidePlotArea = System::Windows::Forms::DataVisualization::Charting::LabelOutsidePlotAreaStyle::Yes;
			series5->SmartLabelStyle->CalloutLineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			series5->SmartLabelStyle->MaxMovingDistance = 80;
			series5->SmartLabelStyle->MinMovingDistance = 20;
			series5->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series5->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->quitDistribution->Series->Add(series5);
			this->quitDistribution->Size = System::Drawing::Size(751, 495);
			this->quitDistribution->TabIndex = 20;
			this->quitDistribution->Text = L"quitDistributionDiagram";
			title2->Alignment = System::Drawing::ContentAlignment::MiddleLeft;
			title2->BackImageWrapMode = System::Windows::Forms::DataVisualization::Charting::ChartImageWrapMode::Unscaled;
			title2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			title2->Name = L"QuitsRatioDistribution";
			title2->Position->Auto = false;
			title2->Position->Height = 4.518281F;
			title2->Position->Width = 94;
			title2->Position->X = 2;
			title2->Position->Y = 2;
			title2->ShadowColor = System::Drawing::Color::White;
			title2->Text = L"QuitsRatioDistribution";
			this->quitDistribution->Titles->Add(title2);
			// 
			// showPRSButton
			// 
			this->showPRSButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->showPRSButton->Location = System::Drawing::Point(43, 523);
			this->showPRSButton->Name = L"showPRSButton";
			this->showPRSButton->Size = System::Drawing::Size(192, 81);
			this->showPRSButton->TabIndex = 18;
			this->showPRSButton->Text = L"Show Player Remaining Status";
			this->showPRSButton->UseVisualStyleBackColor = true;
			this->showPRSButton->Click += gcnew System::EventHandler(this, &MyForm::showPRSButton_Click);
			// 
			// showQDButton
			// 
			this->showQDButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->showQDButton->Location = System::Drawing::Point(256, 523);
			this->showQDButton->Name = L"showQDButton";
			this->showQDButton->Size = System::Drawing::Size(188, 81);
			this->showQDButton->TabIndex = 19;
			this->showQDButton->Text = L"Show Quits Distribution";
			this->showQDButton->UseVisualStyleBackColor = true;
			this->showQDButton->Click += gcnew System::EventHandler(this, &MyForm::showQDButton_Click);
			// 
			// showDCButton
			// 
			this->showDCButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->showDCButton->Location = System::Drawing::Point(465, 523);
			this->showDCButton->Name = L"showDCButton";
			this->showDCButton->Size = System::Drawing::Size(176, 81);
			this->showDCButton->TabIndex = 20;
			this->showDCButton->Text = L"Show Developing Bubble Distribution";
			this->showDCButton->UseVisualStyleBackColor = true;
			this->showDCButton->Click += gcnew System::EventHandler(this, &MyForm::showDCButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(439, 614);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(165, 19);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Total Number of Players: ";
			// 
			// totalPlayerCount
			// 
			this->totalPlayerCount->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->totalPlayerCount->BackColor = System::Drawing::Color::White;
			this->totalPlayerCount->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->totalPlayerCount->Location = System::Drawing::Point(438, 637);
			this->totalPlayerCount->Name = L"totalPlayerCount";
			this->totalPlayerCount->Size = System::Drawing::Size(267, 28);
			this->totalPlayerCount->TabIndex = 22;
			this->totalPlayerCount->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 701);
			this->Controls->Add(this->totalPlayerCount);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->showQDButton);
			this->Controls->Add(this->showPRSButton);
			this->Controls->Add(this->panel);
			this->Controls->Add(this->label_selectedId);
			this->Controls->Add(this->startVisualizeButton);
			this->Controls->Add(this->waitLabel);
			this->Controls->Add(this->loadStatus);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->taskList);
			this->Controls->Add(this->loadDataButton);
			this->Controls->Add(this->showDCButton);
			this->Controls->Add(this->waitWhiteBoard);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"GameDevelopingDesignVisualizer";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->waitWhiteBoard))->EndInit();
			this->panel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->difficultyCurve))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->remainProblemChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quitDistribution))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void LoadData(System::Object^  sender, System::EventArgs^  e) {
		waitWhiteBoard->BringToFront();
		waitLabel->Show();
		waitLabel->BringToFront();
		waitWhiteBoard->Show();
		IO::Stream^ myStream;
		findDataFile = gcnew OpenFileDialog;
		if (findDataFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = findDataFile->OpenFile()) != nullptr)
			{
				String^ file_address = findDataFile->InitialDirectory + findDataFile->FileName;
				string address = marshal_as<std::string>(file_address);
				clock_t begin = clock();
				bool success = Visualizer::Get().LoadPlayerData(address);
				clock_t end = clock();
				double second = double(end - begin) / CLOCKS_PER_SEC;
				cout << "spent " << second << " seconds" << endl;
				if (success)
				{
					MessageBox::Show("Successful Loaded!");
					loadStatus->Text = findDataFile->FileName;
					loadDataButton->Text = "Add More Data";
					startVisualizeButton->Show();
					int playerCount = Visualizer::Get().GetTotalPlayerCount();
					totalPlayerCount->Text = Convert::ToString(playerCount);
				}
				else
					MessageBox::Show("Failured to Load.");
				myStream->Close();
			}
		}
		waitWhiteBoard->Hide();
		waitLabel->Hide();

		//Upadate the tasK list
		map<int, string> taskMap = Visualizer::Get().GetTasklistCopy();
		String^ temp;
		int i = 0;
		for (auto task : taskMap)
		{
			temp = gcnew String(task.second.c_str());
			taskList->Items->Add(temp);
		}
		taskList->DisplayMember = "Task_Name";
		taskList->ValueMember = "Task_Id";


	}
	private: System::Void img_PleaseWait_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		unsigned int selectedId = 0;
		string temp;
		try {
			temp = marshal_as<string>(taskList->SelectedItem->ToString());
			selectedId = Visualizer::Get().SetSelectedTask(temp);
			label_selectedId->Text = Convert::ToString(selectedId);
		}
		catch (exception e) {
		}
	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void startVisualizeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		waitWhiteBoard->BringToFront();
		waitLabel->BringToFront();
		waitLabel->Show();
		waitWhiteBoard->Show();

		map<int, vector<double>> remainingData = Visualizer::Get().GetRemainingData();
		int i = 0;
		for (auto data : remainingData)
		{
			int task_id = data.first;
			String^ task_name = gcnew String(Visualizer::Get().GetTaskNameSystemString(data.first).c_str());

			remainProblemChart->Series->FindByName("RemainNumber")->Points->AddXY(i, data.second[0]);
			remainProblemChart->Series->FindByName("RemainingRatio")->Points->AddXY(i, data.second[1]);
			remainProblemChart->Series->FindByName("QuitNumber")->Points->AddXY(i, data.second[2]);
			remainProblemChart->Series->FindByName("QuittingRatio")->Points->AddXY(i, data.second[3]);

			quitDistribution->Series->FindByName("QuittingRatio")->Points->AddXY(task_name, data.second[3]);
			++i;
		}

		showPRSButton->Show();
		showQDButton->Show();
		showDCButton->Show();
		panel->Show();

		panel->Show();
		waitLabel->Hide();
		waitWhiteBoard->Hide();
		
		startVisualizeButton->Text = "Update Data";
	}
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void showPRSButton_Click(System::Object^  sender, System::EventArgs^  e) {
		difficultyCurve->Hide();
		quitDistribution->Hide();
		remainProblemChart->Show();
	}
	private: System::Void showQDButton_Click(System::Object^  sender, System::EventArgs^  e) {
		difficultyCurve->Hide();
		remainProblemChart->Hide();
		quitDistribution->Show();
	}
		
	private: System::Void showDCButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{

		waitWhiteBoard->Show();
		waitWhiteBoard->BringToFront();
		waitLabel->Show();
		waitLabel->BringToFront();
		if (Visualizer::Get().CheckSelectedTask()) {

			remainProblemChart->Hide();
			quitDistribution->Hide();
			difficultyCurve->Show();


			cout << difficultyCurve->Series->FindByName("deadDistribution")->Points->Count;

			unordered_map<int, pair<unordered_map<double, int>, unordered_map<int, int>>> dCurve = Visualizer::Get().GetDifficultyCurve();
			for (int i = 0; i < dCurve.size() ; ++i) 
			{
				for (auto passRatio : dCurve[i].first)
				{
					for (int n = 0; n < passRatio.second; ++n) {
						difficultyCurve->Series->FindByName("passRatio")->Points->AddXY(i, passRatio.first);
					}
				}
				for (auto deadDistrib : dCurve[i].second) 
				{
					for(int n = 0; n < deadDistrib.second; ++n)
						difficultyCurve->Series->FindByName("deadDistribution")->Points->AddXY(i, deadDistrib.first);
				}
			}
		}
		waitLabel->Hide();
		waitWhiteBoard->Hide();
	}
private: System::Void remainProblemChart_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
