#pragma once

#include "../../../qrutils/generator/abstractGenerator.h"

namespace ubiq {
namespace generator {

/** Generator for Message class. Message is a common class for Ubiq applications,
  it describes data contract between client and server and is generated by
  Data Structures diagram. Each message has some fields containing data, type of
  a message, and error code, for example, message with type "Turn the camera on",
  containing which camera to turn on as data.
  */
class MessageGenerator : public utils::AbstractGenerator
{
public:
	/** Constructor.
	  @param templateDirPath Path to a directory with generation template.
	  @param outputDirPath Path to a directory where Message.cs shall be generated.
	  @param logicalModel Logical model reference.
	  @param errorReporter Object to return errors to.
	  */
	MessageGenerator(QString const &templateDirPath
			, QString const &outputDirPath
			, qReal::LogicalModelAssistInterface const &logicalModel
			, qReal::ErrorReporterInterface &errorReporter
			);

	virtual ~MessageGenerator();

	/// Starts generation.
	void generate();

private:
	/// Generates enum-like set of constants, like NoError = 0; AnError = 1;.
	QString generateEnumElements(qReal::Id const &element) const;

	/// Generates initialization of fields with default values.
	QString generateDefaultFieldsInitialization(qReal::Id const &element) const;

	/// Generates initialization of fields with given values.
	QString generateFieldsInitialization(qReal::Id const &element) const;

	/// Generates formal parameters for constructor that takes all custom fields as parameters.
	QString generateConstructorArguments(qReal::Id const &element) const;

	/// Generates actual arguments for constructor call.
	QString generateConstructorActualArguments(qReal::Id const &element) const;

	/// Generates code for Pack method that serializes all custom fields into byte array.
	QString generatePackFields(qReal::Id const &element) const;

	/// Generates code for Unpack method that deserializes custom fields from byte array.
	QString generateUnpackFields(qReal::Id const &element) const;

	/// Helper function that generates implementation for serialization/deserialization.
	QString generateSerializationRelatedCode(qReal::Id const &element, QString const &method) const;
};

}
}