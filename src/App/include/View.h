#pragma once
#include <QFrame>
#include <QGraphicsView>
#include <map>
#include <gdal_priv.h>
namespace Stone
{
	class View;
	class GraphicsView : public QGraphicsView
	{
		Q_OBJECT
	public:
		GraphicsView(View* view)
			:m_View(view)
		{}

	protected:
#if QT_CONFIG(wheelevent)
		void wheelEvent(QWheelEvent*) override;
#endif
	private:
		View* m_View;
	};

	class View : public QFrame
	{
		Q_OBJECT
	public:
		View();
		GraphicsView* m_GraphicsView;
		int Scale_level = 1;
		int imgWidth;
		int imgHeight;
		float scaleFactor;
		int iScaleWidth;
		int iScaleHeight;
		std::string imagePath;

	public slots:
		void zoomIn();
		void zoomOut();
		void slotRefreshImage();
		void slotOpenImage();
	private:
		void refreshImage();
		QGraphicsPixmapItem* getImgbyBand(QList<GDALRasterBand*>* imgBand);
		unsigned char* imgSketch(float* buffer, GDALRasterBand* currentBand, int bandSize, double noValue);
	};
}