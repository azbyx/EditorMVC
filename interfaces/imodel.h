#pragma once

#include <memory>
#include "iprimitive.h"
#include "observable.h"


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
        @brief Add Point to suite
        @param[in] Point
    */
    virtual void addPoint(const Point&) = 0;

    /*!
        @brief Add line to suite
        @param[in] Point, Point
    */
    virtual void addLine(const Point&, const Point&) = 0;

    /*!
        @brief Add circle to suite
        @param[in] Point, Point
    */
    virtual void addCircle(const Point&, const int&) = 0;

    /*!
        @brief Removes last shape from suite
    */
    virtual void removeLast() = 0;

    /*!
        @brief Redraw of suite
        @param[in]  IPainter
    */
    virtual void draw(IPainterSptr) const = 0;
};

using IModelSptr = std::shared_ptr<IModel>;
