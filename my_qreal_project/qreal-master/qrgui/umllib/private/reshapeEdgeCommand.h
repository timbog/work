#pragma once

#include "controller/commands/edgeElementCommand.h"
#include "controller/commands/trackingEntity.h"

namespace qReal
{
namespace commands
{

class ReshapeEdgeCommand : public EdgeElementCommand, public TrackingEntity
{
public:
	ReshapeEdgeCommand(EdgeElement const *edge);
	ReshapeEdgeCommand(EditorViewScene const *scene, Id const &id);
	virtual ~ReshapeEdgeCommand() {}

	virtual void startTracking();
	virtual void stopTracking();

	bool somethingChanged() const;

protected:
	bool execute();
	bool restoreState();

private:
	void saveConfiguration(QPolygonF &target, Id &src, Id &dst, QPointF &pos, qreal &fromPort, qreal &toPort);
	void applyConfiguration(QPolygonF const &configuration, Id const &src
			, Id const &dst, QPointF const &pos, qreal const &fromPort, qreal const &toPort);

	QPolygonF mOldConfiguration;
	QPolygonF mNewConfiguration;
	QPointF mOldPos;
	QPointF mNewPos;
	Id mOldSrc;
	Id mOldDst;
	Id mNewSrc;
	Id mNewDst;
	qreal mOldFromPort;
	qreal mNewFromPort;
	qreal mOldToPort;
	qreal mNewToPort;
};

}
}
