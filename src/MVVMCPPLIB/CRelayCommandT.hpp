#pragma once
#include "IRelayCommandT.hpp"

namespace Command
{  
    /// <summary>
    /// Concrete template implementation of a function-based relay command.
    /// </summary>
    template<typename T>
    class RelayCommandT :
	    public IRelayCommandT<T>
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
        typedef std::function<void(T parameter)> ExecuteHandler;

        /// <summary>
        /// Defines a function type for the 'can execute' call.
        /// </summary>
        typedef std::function<const bool(T parameter)> CanExecuteHandler;

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="execute"></param>
        /// <param name="canExecute"></param>
        RelayCommandT(const ExecuteHandler& execute, const CanExecuteHandler& canExecute);

        /// <summary>
        /// Destructor.
        /// </summary>
        ~RelayCommandT();

        /// <summary>
        /// Returns whether the command can be executed.
        /// </summary>
        /// <returns></returns>
        const bool canExecute();

        /// <summary>
        /// Provides a strongly-typed variant of <see cref="ICommand.CanExecute(object)"
        /// </summary>
        /// <param name="parameter"></param>
        /// <returns></returns>
        const bool canExecute(T parameter);

        /// <summary>
        /// Triggers the command without arguments.
        /// </summary>
        void execute();

        /// <summary>
        /// Provides a strongly-typed variant of <see cref="ICommand.Execute(object)"
        /// </summary>
        void execute(T parameter);

        /// <summary>
        /// Allows objects to subscribe to changes in the 'canExecute' property.
        /// </summary>
        /// <param name="eventHandler"></param>
        void subscribeCanExecuteChangedEventHandler(const ICommand::CanExecuteChangedEventHandler& eventHandler);

    private:
        ICommand::CanExecuteChangedEventHandler canExecuteChangedEventHandler;
        CanExecuteHandler canExecuteHandler;
        ExecuteHandler executeHandler;

        /// <summary>
        /// Constructor.
        /// </summary>
        RelayCommandT();
    };

    template<typename T>
    inline RelayCommandT<T>::RelayCommandT(const ExecuteHandler& execute, const CanExecuteHandler& canExecute)
    {
        this->executeHandler = execute;
        this->canExecuteHandler = canExecute;
    }

    template<typename T>
    inline RelayCommandT<T>::~RelayCommandT()
    {
    }

    template<typename T>
    inline const bool RelayCommandT<T>::canExecute()
    {
        return this->canExecute(nullptr);
    }

    template<typename T>
    inline const bool RelayCommandT<T>::canExecute(T parameter)
    {
        if (this->canExecuteHandler == nullptr)
            return false;

        return this->canExecuteHandler(parameter);
    }

    template<typename T>
    inline void RelayCommandT<T>::execute(T parameter)
    {
        if (this->executeHandler == nullptr)
            return;

        this->executeHandler(parameter);
    }

    template<typename T>
    inline void RelayCommandT<T>::execute()
    {
        this->execute(nullptr);
    }

    template<typename T>
    inline void RelayCommandT<T>::notifyCanExecuteChanged()
    {
        if (this->canExecuteChangedEventHandler == nullptr)
            return;

        this->canExecuteChangedEventHandler();
    }

    template<typename T>
    inline void RelayCommandT<T>::subscribeCanExecuteChangedEventHandler(const ICommand::CanExecuteChangedEventHandler& eventHandler)
    {
        this->canExecuteChangedEventHandler = eventHandler;
    }

    template<typename T>
    inline RelayCommandT<T>::RelayCommandT()
    {

    }
}