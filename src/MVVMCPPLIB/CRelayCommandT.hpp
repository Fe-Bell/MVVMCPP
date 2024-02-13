#pragma once
#include "IRelayCommandT.hpp"

namespace Command
{
    template<typename T>
    class RelayCommandT :
	    public IRelayCommandT<T>
    {
    public:  
        typedef std::function<void(T parameter)> ExecuteHandler;
        typedef std::function<const bool(T parameter)> CanExecuteHandler;

        RelayCommandT(const ExecuteHandler& execute, const CanExecuteHandler& canExecute);
        ~RelayCommandT();

        const bool canExecute();

        /// <summary>
        /// Provides a strongly-typed variant of <see cref="ICommand.CanExecute(object)"
        /// </summary>
        /// <param name="parameter"></param>
        /// <returns></returns>
        const bool canExecute(T parameter);

        void execute();

        /// <summary>
        /// Provides a strongly-typed variant of <see cref="ICommand.Execute(object)"
        /// </summary>
        void execute(T parameter);

        void notifyCanExecuteChanged();

        void subscribeCanExecuteChangedEventHandler(const ICommand::CanExecuteChangedEventHandler& eventHandler);

    private:
        ICommand::CanExecuteChangedEventHandler canExecuteChangedEventHandler;
        CanExecuteHandler canExecuteHandler;
        ExecuteHandler executeHandler;

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