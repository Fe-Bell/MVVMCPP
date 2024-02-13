#pragma once
#include <functional>

namespace Command 
{
    /// <summary>
    /// Interface that defines a basic contract for an MVVM command. 
    /// </summary>
    class ICommand
    {
    protected:
        /// <summary>
        /// Constructor.
        /// </summary>
        ICommand() {};

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~ICommand() {};

    public:
        /// <summary>
        /// Raised when the ability of the command to execute has changed.
        /// </summary>
        typedef std::function<void()> CanExecuteChangedEventHandler;

        /// <summary>
        /// Returns whether the command can be executed.
        /// </summary>
        /// <returns></returns>
        virtual const bool canExecute() = 0;

        /// <summary>
        /// Triggers the command without arguments.
        /// </summary>
        virtual void execute() = 0;

        /// <summary>
        /// Allows objects to subscribe to changes in the 'canExecute' property.
        /// </summary>
        /// <param name="eventHandler"></param>
        virtual void subscribeCanExecuteChangedEventHandler(const CanExecuteChangedEventHandler& eventHandler) = 0;
    };
}
