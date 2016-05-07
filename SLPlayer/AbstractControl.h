#pragma once
#include "AbstractView.h"
#include "AbstractController.h"

class AbstractControl:virtual public AbstractView,virtual public AbstractController
{
public:
	AbstractControl() = default;
	~AbstractControl() = default;
};
