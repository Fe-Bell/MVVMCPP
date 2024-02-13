#pragma once
#include <functional>

namespace Command 
{
    class ICommand
    {
    private:


    protected:
        ICommand() {};
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

        virtual void execute() = 0;

        virtual void subscribeCanExecuteChangedEventHandler(const CanExecuteChangedEventHandler& eventHandler) = 0;
    };
}
