#pragma once
#include "IRelayCommand.hpp"

namespace Command
{
    class RelayCommand :
	    public IRelayCommand
    {
    public:
        typedef std::function<void()> ExecuteHandler;
        typedef std::function<const bool()> CanExecuteHandler;

        RelayCommand(const ExecuteHandler& execute, const CanExecuteHandler& canExecute);
	    ~RelayCommand();

        /// <summary>
        /// Returns whether the command can be executed.
        /// </summary>
        /// <returns></returns>
        const bool canExecute();

        void execute();

        void subscribeCanExecuteChangedEventHandler(const CanExecuteChangedEventHandler& eventHandler);

        void notifyCanExecuteChanged();

    private:	  
        CanExecuteChangedEventHandler canExecuteChangedEventHandler; 
        CanExecuteHandler canExecuteHandler; 
        ExecuteHandler executeHandler;

        RelayCommand();
    };
}

