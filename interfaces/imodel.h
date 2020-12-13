#pragma once

#include "../interfaces/iprimitive.h"
#include "../headers/observable.h"


/**
 * \interface IModel
 * @brief Here is model for keeping primitive objects.
 */
class IModel : public Observable {

  public:
    virtual ~IModel() = default;

    /*!
        @brief Create new suite
    */
    virtual void newModel() = 0;

    /*!
        @brief Open suite from file
        @param[in] file_name
    */
    virtual void openModel(std::string&) = 0;

    /*!
        @brief Save current suite
    */
    virtual void saveModel() = 0;

    /*!
        @brief Add point to suite
        @param[in] point
    */
    virtual void addPoint(const point&) = 0;

    /*!
        @brief Add line to suite
        @param[in] point, dot
    */
    virtual void addLine(const point&, const dot&) = 0;

    /*!
        @brief Add circle to suite
        @param[in] point, dot
    */
    virtual void addCircle(const point&, const int&) = 0;

    /*!
        @brief Removes last shape from suite
    */
    virtual void removeLast() = 0;

    /*!
        @brief Redraw of suite
        @param[in]  IPainter
    */
    virtual void draw(std::shared_ptr<IPainter>) const = 0;
};

