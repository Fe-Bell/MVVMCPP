#pragma once
#include "IRelayCommand.hpp"

namespace Command
{
    /// <summary>
    /// Concrete implementation of a function-based relay command.
    /// </summary>
    class RelayCommand :
	    public IRelayCommand
    {
    protected:
        /// <summary>
        /// Notifies that the <see cref="ICommand.CanExecute"/> property has changed.
        /// </summary>
        void notifyCanExecuteChanged();

    public:
        /// <summary>
        /// Defines a function type for the the 'execute' call.
        /// </summary>
        typedef std::function<void()> ExecuteHandler;

        /// <summary>
        /// Defines a function type for the 'can execute' call.
        /// </summary>
        typedef std::function<const bool()> CanExecuteHandler;

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="execute"></param>
        /// <param name="canExecute"></param>
        RelayCommand(const ExecuteHandler& execute, const CanExecuteHandler& canExecute);

	    /// <summary>
	    /// Destructor.
	    /// </summary>
	    ~RelayCommand();

        /// <summary>
        /// Returns whether the command can be executed.
        /// </summary>
        /// <returns></returns>
        const bool canExecute();

        /// <summary>
        /// Triggers the command without arguments.
        /// </summary>
        void execute();

        /// <summary>
        /// Allows objects to subscribe to changes in the 'canExecute' property.
        /// </summary>
        /// <param name="eventHandler"></param>
        void subscribeCanExecuteChangedEventHandler(const CanExecuteChangedEventHandler& eventHandler);

    private:	  
        CanExecuteChangedEventHandler canExecuteChangedEventHandler; 
        CanExecuteHandler canExecuteHandler; 
        ExecuteHandler executeHandler;

        RelayCommand();
    };
}

