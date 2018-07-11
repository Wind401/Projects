Rails.application.routes.draw do
  
  # default_url_options :host => "doggie-walk-jza154.c9users.io"
  
  resources :events
  resources :dogs
  resources :posts
  devise_for :admin_users, ActiveAdmin::Devise.config
  ActiveAdmin.routes(self)
  get 'index' => 'page#home'

  get 'search' => 'page#search'

  get 'privacy'=>'page#privacy'
  get 'terms'=>'page#terms'
  
  # ContactUS routes
  # resources :contact_from
  get '/contact_us' => 'contacts#new'
  # get '/contacts'=> 'contacts#index'
  post 'contacts' => 'contacts#create'
  delete 'contacts' => 'contacts#destroy'

  get 'users' => 'users#index'
  
  devise_for :users , :controllers => { :registrations => :registrations }
  
  # resources :users
  # The priority is based upon order of creation: first created -> highest priority.
  # See how all your routes lay out with "rake routes".

  # You can have the root of your site routed with "root"
  root 'page#home'
  resources 'users' do
    resources :reviews, expect: [:index, :show]
    # resources :reviews, only: [:new, :index], expect: [:index]
  end
    
  get "mailbox/inbox" => "mailbox#inbox", as: :mailbox_inbox
  get 'mailbox/sentbox' => 'mailbox#sentbox', as: :mailbox_sentbox
  get "mailbox/trash" => "mailbox#trash", as: :mailbox_trash
  
  resources :conversations do
    member do
      post :reply
      post :trash
      post :untrash
    end
  end

end
