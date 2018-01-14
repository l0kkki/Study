#include "stdafx.h"
#include "TrainTests.h"


TrainTests::TrainTests()
{
}


TrainTests::~TrainTests()
{
}

bool TrainTests::CountTest()
{
	LoggerFactory factory;
	ILogger* logger = factory.Create(File);
	Train train(logger);
	train.Add(true);
	train.Add(false);
	train.Add(false);
	train.Add(false);
	train.Add(true);
	train.Add(false);
	train.Add(true);

	if (train.Count() != 7)
	{
		logger->Error("Invalid result" + train.Count());
	}
	else
	{
		logger->Information("Valid result");
	}

	return true;
}
