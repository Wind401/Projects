class ApplicationController < ActionController::Base
  # Prevent CSRF attacks by raising an exception.
  # For APIs, you may want to use :null_session instead.
  protect_from_forgery with: :exception
  
  before_action :configure_permitted_parameters, if: :devise_controller?
  
  helper_method :mailbox, :conversation
  
  # def default_url_options
  #   if Rails.env.production?
  #     {:host => "afternoon-refuge-86211.herokuapp.com"}
  #   else  
  #     {:host => "doggie-walk-jza154.c9users.io"}
  #   end
  # end 
  
  private

  def mailbox
    @mailbox ||= current_user.mailbox
  end

  def conversation
    @conversation ||= mailbox.conversations.find(params[:id])
  end
  
  protected 

  def configure_permitted_parameters
    devise_parameter_sanitizer.for(:sign_up){|u| u.permit(:first_name, :last_name,:birthday,:email,:password,:password_confirmation,:remember_me, :longitude, :latitude, :address)}
    devise_parameter_sanitizer.for(:sign_in){|u| u.permit(:email,:password,:remember_me, :longitude, :latitude)}
    devise_parameter_sanitizer.for(:account_update){|u| u.permit(:first_name, :last_name,:birthday,:dog_breed,:dog_weight,:dog_age,:address,:about,:email,:password,:current_password,:remember_me, :image,:longitude, :latitude)}

  end 
end
 