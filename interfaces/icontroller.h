#pragma once

#include "../headers/base_types.h"
#include <string>

/**
 * \interface IController
 * @brief Here is controlls the model
 */

class IController {
  public:
    IController() = default;
    virtual ~IController() = default;

    /**
    * @brief Clearing current model
    */
    virtual void commandClear() = 0;

    /**
    * @brief Adds shape point to current model
    */
    virtual void commandNewPoint(const point&) = 0;

    /**
    * @brief Adds shape line to current model
    */
    virtual void commandNewLine(const point&, const dot&) = 0;

    /**
    * @brief Adds shape circle to current model
    */
    virtual void commandNewCircle(const point&, const int&) = 0;

    /**
    * @brief Removes last shape from current model
    */
    virtual void commandRemoveShape() = 0;

    /**
    * @brief loads the model from file
    */
    virtual void commandOpenSuite(const std::string&) = 0;

    /**
    * @brief saves the model to file
    */
    virtual void commandSaveSuite(const std::string&) = 0;


    /**
    * @brief starts processing user commands
    */
    virtual void loop() = 0;

  private:
    /**
    * @brief Reads user commands to process current model
    */
    virtual bool readCommand() = 0;

};
