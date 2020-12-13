#pragma once

#include "../headers/registry.h"
#include "../interfaces/imodel.h"

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
    virtual void newModel() override;

    /*!
        @brief Save suite
    */
    virtual void saveModel() override;

    /*!
        @brief Open new suite
        @param[in] file_path_name
    */
    virtual void openModel(std::string&) override;

    /*!
        @brief Add point to suite
        @param[in] point
    */
    virtual void addPoint(const point&) override;

    /*!
        @brief Add line to suite
        @param[in] point, dot
    */
    virtual void addLine(const point&, const dot&) override;

    /*!
        @brief Add circle to suite
        @param[in] point, dot
    */
    virtual void addCircle(const point&, const int&) override;

    /*!
        @brief Removes last shape from suite
    */
    virtual void removeLast() override;

    /*!
        @brief Draw all primitive from suite
        @param[in] IPainter
    */
    virtual void draw(std::shared_ptr<IPainter>) const override;

private:
    std::list<std::unique_ptr<IPrimitiveObject>> keeperObjects;
    RegistryObjects factoryObjects;
};

