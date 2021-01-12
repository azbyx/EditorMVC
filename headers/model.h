#pragma once

#include "registry.h"
#include "imodel.h"

/**
	\brief There is class of model of the graphic editor.
*/
class Model : public IModel {

  public:
    Model() = default;
    ~Model() = default;

    /*!
        @brief Create new suite
    */
    void newModel() override;

    /*!
        @brief Save suite
    */
    void saveModel() override;

    /*!
        @brief Open new suite
        @param[in] file_path_name
    */
    void openModel(std::string&) override;

    /*!
        @brief Add Point to suite
        @param[in] Point
    */
    void addPoint(const Point&) override;

    /*!
        @brief Add line to suite
        @param[in] Point, Point
    */
    void addLine(const Point&, const Point&) override;

    /*!
        @brief Add circle to suite
        @param[in] Point, Point
    */
    void addCircle(const Point&, const int&) override;

    /*!
        @brief Removes last shape from suite
    */
    void removeLast() override;

    /*!
        @brief Draw all primitive from suite
        @param[in] IPainter
    */
    void draw(std::shared_ptr<IPainter>) const override;

private:
    std::list<std::unique_ptr<IPrimitiveObject>> keeperObjects;
    RegistryObjects factoryObjects;
};

